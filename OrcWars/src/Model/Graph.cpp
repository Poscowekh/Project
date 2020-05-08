// Graph.cpp for Model

#include "Graph.h"

using namespace std;
namespace GameModel
{
    Graph::Graph(pair<int, int> snakes_head_coordinates, Matrix matrix)
    {
        height = matrix.get_rows();
        width = matrix.get_columns();
        snakes_head = snakes_head_coordinates;
        food = matrix.get_food();
        //block = matrix.get_blocks();
        create_map();
    }

    void Graph::create_map()
    {
        for(int i = 0; i < height; i++)
            for(int j = 0; j < width; j++)
            {
                int tmp_key = width*j + i;
                Node tmp_node(make_pair(i,j), 0, tmp_key);
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
                size_t tmp_key = width*j + i;
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
            tmp_node.set_up(tmp_key + 1);
        if(tmp_node.get_coordinates().first - 1 > 0)
            tmp_node.set_down(tmp_key - 1);
        if(tmp_node.get_coordinates().second + 1 < width)
            tmp_node.set_down(tmp_key + width);
        if(tmp_node.get_coordinates().second - 1 > 0)
            tmp_node.set_up(tmp_key - width);
    }

    size_t Graph::Dijkstra(pair<int, int> food_coords)
    {
        //neighbours
    }
}
