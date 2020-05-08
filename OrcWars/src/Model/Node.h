// Node.h for Model

#ifndef NODE_H
#define NODE_H
#include <stdlib.h>
#include <string>
#include <utility>
#include <map>
#include "Node.h"
using namespace std;
namespace GameModel
{
    class Node
    {
        private:
            pair<int, int> coordinates;
            size_t value;
            size_t key;
            bool visit_flag;
            map<string, int> neighbours;    //keys here
            //size_t value_in               //Depends on type of terrain, maybe food or smth else
            //size_t value_out              //Depends on type of terrain, maybe food or smth else
        public:
            Node(pair<int, int> new_coordinates, size_t initial_value, size_t new_key);
            pair<int, int> get_coordinates();
            size_t get_value();
            size_t get_key();
            size_t get_neighbour(string direction);
            void set_value(size_t new_value);
            bool get_visit_flag();
            void mark_as_visited();
            void set_up(size_t tmp_key);
            void set_right(size_t tmp_key);
            void set_down(size_t tmp_key);
            void set_left(size_t tmp_key);
    };
}
#endif // NODE_H
