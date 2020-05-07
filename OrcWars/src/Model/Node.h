// Node.h for Model

#ifndef NODE_H
#define NODE_H
#include <stdlib.h>
#include <utility>
#include <vector>
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
            vector<int> neighbours;    //keys here
            //size_t movement_value   //Depends on type of terrain, maybe food or smth else
        public:
            Node(pair<int, int> new_coordinates, size_t initial_value, size_t new_key);
            pair<int, int> get_coordinates();
            size_t get_value();
            size_t get_key();
            void set_value(size_t new_value);
            bool get_visit_flag();
            void mark_as_visited();
    };
}
#endif // NODE_H
