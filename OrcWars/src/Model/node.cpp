// node.cpp for Model

#include "node.h"

namespace GameModel
{
    using namespace std;

    Node::Node(pair<int, int> new_coordinates, size_t initial_value)
    {
        coordinates = new_coordinates;
        value = initial_value;
        visit_flag = false;
    }

    Node::get_coordinates()
    {
        return coordinates;
    }

    Node::get_value()
    {
        return value;
    }

    Node::set_value(size_t new_value)
    {
        value = new_value;
    }

    Node::get_visit_flag()
    {
        return visit_flag;
    }

    Node::mark_as_visited()
    {
        visit_flag = true;
    }
}
