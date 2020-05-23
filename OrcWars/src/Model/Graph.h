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
            size_t height;
            size_t width;
            size_t shift;
            size_t count;
            size_t infinity;
            size_t head_key;
            map<size_t, Node> nodes;
            vector< pair<size_t, size_t> > food;  //food indexes and distance
            vector<size_t> way;                //contains keys
            spMatrix matrix;
            pair<size_t, size_t> snakes_head;
        public:
            Graph(size_t id, spMatrix matrix);
            vector< pair<size_t, size_t> > sort_distance_vector(vector< pair<size_t, size_t> > vect);
            size_t get_height();
            size_t get_width();
            size_t get_count();
            size_t get_distance();
            pair<size_t, size_t> get_initial_values(pair<size_t, size_t>);
            pair<size_t, size_t> get_coords(size_t key);
            pair<size_t, size_t> get_snake_head();
            pair<size_t, size_t> any_move();
            vector<size_t> safe_way(size_t diff_dist);
            void Dijkstra();
            void count_from_node(Node* init_node);
            void recount_distance_to_node(Node* init_node);
            void recount_distance_to_neighbours(Node* init_node);
            void count_next_nodes(Node* init_node);
            void recheck_distances(Node* init_node);
            void build_way(size_t food_key);
            void unmark_nodes();
            int choose_node(size_t key);
            vector<size_t> get_way();
            void set_neighbours(pair<size_t, size_t> coords, size_t tmp_key);
            void create_map();
            void print_graph();
            void print_distance();
            void print_keys();
    };
}
#endif // GRAPH_H
