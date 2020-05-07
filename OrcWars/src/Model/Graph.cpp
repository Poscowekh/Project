// Graph.cpp for Model

#include "Graph.h"

using namespace std;
namespace GameModel
{
    Graph::Graph(pair<int, int> snakes_head_coordinates, pair<int, int> food_coordinates)
    {
        height = abs(snakes_head_coordinates.first - food_coordinates.first) + 1;
        width = abs(snakes_head_coordinates.second - food_coordinates.second) + 1;
        snakes_head = snakes_head_coordinates;
        food = food_coordinates;
        if(snakes_head_coordinates.first - food_coordinates.first >= 0)
        {
            if(snakes_head_coordinates.second - food_coordinates.second >= 0)
                quarter = "II";
            else
                quarter = "I";
        }
        else
        {
            if(snakes_head_coordinates.second - food_coordinates.second >= 0)
                quarter = "III";
            else
                quarter = "IV";
        }
    }

    void Graph::create_map()
    {
        for(int i = 0; i < height; i++)
            for(int j = 0; j < width; j++)
            {
                int tmp_key = width*j + i;
                Node tmp_node(make_pair(i,j), 0, tmp_key);
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

    string Graph::get_quarter()
    {
        return quarter;
    }

    //size_t Graph::Dijkstra()
}
