// node.h for Model

#ifndef NODE_H
#define NODE_H
#include <stdlib.h>
#include <utility>
#include "node.h"
using namespace std;
namespace GameModel
{
    class Node
    {
        private:
            pair<int, int> coordinates;
            size_t value;
            bool visit_flag;
        public:
            Node(pair<int, int> new_coordinates, size_t initial_value);
            pair<int, int> get_coordinates();
            size_t get_value();
            void set_value(size_t new_value);
            bool get_visit_flag();
            void mark_as_visited();
    };
}
#endif // NODE_H
