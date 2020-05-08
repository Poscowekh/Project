// Graph.cpp for Model

#ifndef GRAPH_H
#define GRAPH_H
#include <stdlib.h>
#include <iostream>
#include <map>
#include <vector>
#include "Node.h"
#include "Matrix.h"
using namespace std;
namespace GameModel
{
    class Graph
    {
        private:
            int height;
            int width;
            map<int, Node> nodes;
            //vector<int> marked_nodes;
            vector<Food> food;
            Matrix matrix;
            vector< pair<int, int> > ways;
            pair<int, int> snakes_head;
        public:
            Graph(pair<int, int> snakes_head_coordinates, Matrix matrix);
            size_t get_height();
            size_t get_width();
            size_t get_count();
            size_t Dijkstra(pair<int, int> food_coords);
            void set_neighbours(Node tmp_node, size_t tmp_key);
            void create_map();
            void print_graph();
    };
}
#endif // GRAPH_H
