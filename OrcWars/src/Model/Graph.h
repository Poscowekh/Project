// Graph.cpp for Model

#ifndef GRAPH_H
#define GRAPH_H
#include <stdlib.h>
#include <iostream>
#include <map>
#include <vector>
#include "Node.h"
using namespace std;
namespace GameModel
{
    class Graph
    {
        private:
            int height;
            int width;
            map<int, Node> nodes;
            vector<int> marked_nodes;
            pair<int, int> food;
            pair<int, int> snakes_head;
            string quarter;
        public:
            Graph(pair<int, int> snakes_head_coordinates, pair<int, int> food_coordinates);
            size_t get_height();
            size_t get_width();
            size_t get_count();
            string get_quarter();
            size_t Dijkstra();
            void create_map();
            void print_graph();
    };
}
#endif // GRAPH_H
