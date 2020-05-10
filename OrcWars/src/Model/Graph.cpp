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
    }

    pair<size_t, size_t> Graph::get_initial_values(pair<int, int> coords)
    {
        size_t matrix_value = matrix->get_value(coords); //rework for terrain
        size_t in = 1;
        size_t out = 0;
        if(matrix_value == 8 || matrix_value == 1 || matrix_value == 3)
                in = 2 * shift;
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
                set_neighbours(tmp_node, tmp_key);
                //tmp_node.set_value();
                nodes.insert(make_pair(tmp_key, tmp_node));
            }
    }

    void Graph::print_graph()
    {
        int tmp = 0;
        for(int i = 0; i < height; i++)
            for(int j = 0; j < width; j++)
            {
                tmp++;
                size_t tmp_key = shift * j + i;
                pair<int, int> tmp_pair = nodes.at(tmp_key).get_coordinates();
                cout << tmp_key << ' ' << '(' << tmp_pair.first << ',' << tmp_pair.second <<')' << ' ';
            };
        cout << "||" << tmp << "||" << endl;
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

    void Graph::set_neighbours(Node tmp_node, size_t tmp_key)
    {
        if(tmp_node.get_coordinates().first + 1 < height)
            tmp_node.add_neighbour(tmp_key + 1);
        if(tmp_node.get_coordinates().first - 1 > 0)
            tmp_node.add_neighbour(tmp_key - 1);
        if(tmp_node.get_coordinates().second + 1 < width)
            tmp_node.add_neighbour(tmp_key + shift);
        if(tmp_node.get_coordinates().second - 1 > 0)
            tmp_node.add_neighbour(tmp_key - shift);
    }

    void Graph::count_from_node(Node init_node, Node prev_node)
    {
        vector<int> neighbours_keys = init_node.get_neighbours_keys();
        if(/*init_node.get_way_to().back() != init_node.get_key() || */init_node.get_key() != prev_node.get_key())   //?????
        init_node.set_way_to(init_node.get_way_to());
        Node next_node = Node();
        for(size_t i = 0; i < init_node.get_neighbours_count(); i++)
        {
            if(!nodes[neighbours_keys[i]].get_visit_flag())
                if(prev_node.get_key() != nodes[neighbours_keys[i]].get_key())
                {
                    int distance = init_node.get_distance() + /*init_node.get_values().second +*/ nodes[neighbours_keys[i]].get_values().first;
                    if(nodes[neighbours_keys[i]].get_distance() == 0)
                    {
                        nodes[neighbours_keys[i]].set_distance(distance);
                        count_from_node(nodes[neighbours_keys[i]], init_node);
                    }
                    else
                        if(distance < nodes[neighbours_keys[i]].get_distance())
                        {
                            nodes[neighbours_keys[i]].set_distance(distance);
                            count_from_node(nodes[neighbours_keys[i]], init_node);
                        }
                        else
                            count_from_node(nodes[neighbours_keys[i]], init_node);
                }
        }
        init_node.mark_as_visited();
    }

    void Graph::Dijkstra()
    {
        Node init_node = Node();
        init_node = nodes[snakes_head.first + snakes_head.second * shift];
        count_from_node(init_node, init_node);
        for(size_t i = 0; i < food.size(); i++)
        {//pair index,distance
            pair<int, int> coords = matrix->get_food()[food[i].first].get_coordinates();
            food[i].second = nodes[shift * coords.second + coords.first].get_distance();
            cout << "||||||||||||||||" << food[i].second << "||" << food.size()<< endl; //set to 10 ?
            ;
        }
    }
}
