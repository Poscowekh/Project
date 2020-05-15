// Graph.cpp for Model

#include "Graph.h"

using namespace std;
namespace GameModel
{
    Graph::Graph(pair<int, int> snakes_head_coordinates, spMatrix mtrx)
    {
        matrix = mtrx;
        height = matrix->get_rows();
        width = matrix->get_columns();
        snakes_head = snakes_head_coordinates;
        for(size_t i = 0; i < matrix->get_food_count(); i++)
            food.push_back(make_pair(i, 0));
        if(height >= width)
            shift = height;
        else
            shift = width;
        create_map();
    }

    pair<size_t, size_t> Graph::get_initial_values(pair<int, int> coords)
    {
        size_t matrix_value = matrix->get_value(coords); //rework for terrain
        size_t in = 1;
        size_t out = 0;
        if(matrix_value == 8 || matrix_value == 1 || matrix_value == 3)
            in = 5 * shift;
        return make_pair(in, out);
                       //Maybe add terrain types here later
    }

    void Graph::create_map()
    {
        for(int i = 0; i < height; i++)
            for(int j = 0; j < width; j++)
            {
                int tmp_key = shift * j + i;
                pair<size_t, size_t> values = get_initial_values(make_pair(i,j));
                Node tmp_node(make_pair(i,j), values.first, values.second, tmp_key);
                tmp_node.set_distance(5 * shift);
                nodes.insert(make_pair(tmp_key, tmp_node));
                set_neighbours(tmp_node.get_coordinates(), tmp_key);
            }
    }

    void Graph::print_graph()
    {
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                size_t tmp_key = shift * j + i;
                cout << tmp_key << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }

    size_t Graph::get_height()
    {
        return height;
    }

    size_t Graph::get_width()
    {
        return width;
    }

    size_t Graph::get_count()
    {
        return height*width;
    }

    void Graph::set_neighbours(pair<int, int> coords, size_t tmp_key)
    {
        if(coords.first + 1 < height)
            nodes[tmp_key].add_neighbour(tmp_key + shift);
        if(coords.first - 1 >= 0)
            nodes[tmp_key].add_neighbour(tmp_key - shift);
        if(coords.second + 1 < width)
            nodes[tmp_key].add_neighbour(tmp_key + 1);
        if(coords.second - 1 >= 0)
            nodes[tmp_key].add_neighbour(tmp_key - 1);
    }

    void Graph::count_from_node(Node* init_node)
    {
        Node* tmp_node = new Node();
        int distance;
        vector< pair<int, int> > distance_vector;       //key,distance
        for(size_t i = 0; i < init_node->get_neighbours_count(); i++)
        {
            int tmp_key = init_node->get_neighbours_keys()[i];
            tmp_node = &nodes[tmp_key];
            if(!tmp_node->get_visit_flag())
            {
                distance = init_node->get_distance() + tmp_node->get_values().first;
                if(distance < tmp_node->get_distance())
                    tmp_node->set_distance(distance);
            }
            if(tmp_node->get_distance() < 5 * shift)
                distance_vector.push_back(make_pair(tmp_key, tmp_node->get_distance()));
        }
        init_node->mark_as_visited();
        distance_vector = sort_distance_vector(distance_vector);
        for(size_t i = 0; i < distance_vector.size(); i++)
        if(!(nodes[distance_vector[i].first].get_visit_flag()))
            count_from_node(&(nodes[distance_vector[i].first]));
    }

    vector< pair<int, int> > Graph::sort_distance_vector(vector< pair<int, int> > vect)
    {
        for(size_t i = 0; i < vect.size(); i++)
            for(size_t j = i; j < vect.size(); j++)
                if(vect[i].second > vect[j].second)
                {
                    pair<int, int> tmp = vect[i];
                    vect[i] = vect[j];
                    vect[j] = vect[i];
                }
        return vect;
    }

    void Graph::print_distance()
    {
        cout << endl;
        cout << "  ";
        for(size_t i = 0; i < matrix->get_columns(); i++)
            cout << i + 1 << ' ';
        cout << endl;
        for(size_t i = 0; i < height; i++)
        {
            cout << i + 1 << ' ';
            for(size_t j = 0; j < width; j++)
            {
                if(nodes[shift * j + i].get_distance() == 5 * shift)
                    cout << "- ";
                else
                    cout << nodes[shift * j + i].get_distance() << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }

    void Graph::build_way(int food_key, int head_key)
    {
        bool flag = true;
        int tmp_key = food_key;
        while(tmp_key != head_key && flag)
        {
           way.push_back(tmp_key);
           tmp_key = choose_node(tmp_key);
           if(tmp_key == -1)
               flag = false;
        }
        way.pop_back();
    }

    int Graph::choose_node(int key)
    {
        bool flag;
        int next_key;
        int distance = nodes[key].get_distance();
        vector<int> neighbours = nodes[key].get_neighbours_keys();
        for(size_t i = 0; i < neighbours.size(); i++)
            if(nodes[neighbours[i]].get_distance() < distance && neighbours[i] < shift * shift)
            {
                next_key = neighbours[i];
                distance = nodes[next_key].get_distance();
                flag = true;
            }
        if(flag)
            return next_key;
        else
            return -1;
    }

    void Graph::Dijkstra()
    {
        int init_key = snakes_head.first + snakes_head.second * shift;
        nodes[init_key].set_distance(0);
        count_from_node(&nodes[init_key]);
        int food_key = matrix->get_food()[0].get_coordinates().first + matrix->get_food()[0].get_coordinates().second * shift;
        build_way(food_key, init_key);
    }

    int Graph::get_distance()
    {
        int food_key = matrix->get_food()[0].get_coordinates().first + matrix->get_food()[0].get_coordinates().second * shift;
        return nodes[food_key].get_distance();
    }

    vector<int> Graph::get_way()
    {
        return way;
    }
}
