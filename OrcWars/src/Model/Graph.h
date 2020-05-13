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
            int shift;
            map<int, Node> nodes;
            vector< pair<int, int> > food;  //food indexes and distance
            Matrix* matrix;
            pair<int, int> snakes_head;
        public:
            Graph(pair<int, int> snakes_head_coordinates, Matrix* matrix);
            vector< pair<int, int> > sort_distance_vector(vector< pair<int, int> > vect);
            size_t get_height();
            size_t get_width();
            size_t get_count();
            pair<size_t, size_t> get_initial_values(pair<int, int>);
            void Dijkstra();
            void count_from_node(Node* init_node, Node* prev_node);
            void set_neighbours(pair<int, int> coords, size_t tmp_key);
            void create_map();
            void print_graph();
            void print_distance();
    };
}
#endif // GRAPH_H
