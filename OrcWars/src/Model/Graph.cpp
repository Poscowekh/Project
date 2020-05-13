// Graph.cpp for Model

#include "Graph.h"

using namespace std;
namespace GameModel
{
    Graph::Graph(pair<int, int> snakes_head_coordinates, Matrix* mtrx)
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
                cout << nodes[tmp_key].get_neighbours_count() << ' ';
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
            nodes[tmp_key].add_neighbour(tmp_key + 1);
        if(coords.first - 1 >= 0)
            nodes[tmp_key].add_neighbour(tmp_key - 1);
        if(coords.second + 1 < width)
            nodes[tmp_key].add_neighbour(tmp_key + shift);
        if(coords.second - 1 >= 0)
            nodes[tmp_key].add_neighbour(tmp_key - shift);
    }

    void Graph::count_from_node(Node* init_node, Node* prev_node)
    {
        if(!init_node->get_visit_flag() && init_node->get_distance() < 5 * shift)
        {
            //vector<int> neighbours_keys = init_node.get_neighbours_keys();
            //if(/*init_node.get_way_to().back() != init_node.get_key() || */init_node.get_key() != prev_node.get_key())   //?????
            //init_node.set_way_to(init_node.get_way_to());
            init_node->mark_as_visited();
            vector< pair<int, int> > distance_vector;
            for(size_t i = 0; i < init_node->get_neighbours_count(); i++)
            {
                Node* tmp_node = &nodes[init_node->get_neighbours_keys()[i]];
                if(tmp_node->get_key() != prev_node->get_key())
                {
                    int distance = init_node->get_distance() + tmp_node->get_values().first;
                    if(tmp_node->get_distance() > distance || tmp_node->get_distance() == 0)
                        tmp_node->set_distance(distance);
                    distance_vector.push_back(make_pair(tmp_node->get_key(), tmp_node->get_distance()));
                }
            }
            distance_vector = sort_distance_vector(distance_vector);
            for(size_t i = 0; i < distance_vector.size(); i++)
            {
                int tmp_key = distance_vector[i].first;
                count_from_node(&nodes[tmp_key], init_node);
            }
        }
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
        for(size_t i = 0; i < height; i++)
        {
            for(size_t j = 0; j < width; j++)
                cout << nodes[shift * j + i].get_distance() << ' ';
            cout << endl;
        }
        cout << endl;
    }

    void Graph::Dijkstra()
    {
        int init_key = snakes_head.first + snakes_head.second * shift;
        nodes[init_key].set_distance(0);
        count_from_node(&nodes[init_key], &nodes[init_key]);
        //for(size_t i = 0; i < food.size(); i++)
        //{//pair index,distance
        //    pair<int, int> coords = matrix->get_food()[food[i].first].get_coordinates();
        //   food[i].second = nodes[shift * coords.second + coords.first].get_distance();
        //    cout << "||||||||||||||||" << food[i].second << "||" << food.size()<< endl; //set to 10 ?
    }
}
