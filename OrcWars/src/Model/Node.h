// Node.h for Model

#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include "Node.h"

using namespace std;
namespace GameModel
{
    class Node
    {
        private:
            pair<int, int> coordinates;
            size_t distance;
            size_t key;
            bool visit_flag;
            vector<int> way_to;
            vector<int> neighbours;        //keys here
            size_t value_in;               //Depends on type of terrain, maybe food or smth else
            size_t value_out;              //--||--||--
        public:
            Node(pair<int, int> new_coordinates, size_t new_value_in, size_t new_value_out, size_t new_key);
            Node();
            pair<int, int> get_coordinates();
            pair<int, int> get_values();
            size_t get_distance();
            size_t get_key();
            size_t get_neighbours_count();
            vector<int> get_way_to();
            vector<int> get_neighbours_keys();
            void set_way_to(vector<int> way_to_prev);
            void set_distance(size_t new_distance);
            void set_value_in(size_t new_value);
            void set_value_out(size_t new_value);
            bool get_visit_flag();
            void mark_as_visited();
            void add_neighbour(size_t tmp_key);
    };
}
#endif // NODE_H
