// Node.cpp for Model

#include "Node.h"

using namespace std;
namespace GameModel
{
    Node::Node(pair<int, int> new_coordinates, size_t initial_value, size_t new_key)
    {
        coordinates = new_coordinates;
        value = initial_value;
        visit_flag = false;
        key = new_key;
    }

    pair<int, int> Node::get_coordinates()
    {
        return coordinates;
    }

    size_t Node::get_value()
    {
        return value;
    }

    size_t Node::get_key()
    {
        return key;
    }

    void Node::set_value(size_t new_value)
    {
        value = new_value;
    }

    bool Node::get_visit_flag()
    {
        return visit_flag;
    }

    void Node::mark_as_visited()
    {
        visit_flag = true;
    }
}
