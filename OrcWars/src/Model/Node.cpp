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

    void Node::set_up(size_t tmp_key)
    {
        pair<int, int> up = make_pair(coordinates.first - 1, coordinates.second);
        neighbours.insert(make_pair("up", tmp_key));
    }

    void Node::set_right(size_t tmp_key)
    {
        pair<int, int> up = make_pair(coordinates.first, coordinates.second + 1);
        neighbours.insert(make_pair("right", tmp_key));
    }

    void Node::set_down(size_t tmp_key)
    {
        pair<int, int> down = make_pair(coordinates.first + 1, coordinates.second);
        neighbours.insert(make_pair("down", tmp_key));
    }

    void Node::set_left(size_t tmp_key)
    {
        pair<int, int> left = make_pair(coordinates.first, coordinates.second - 1);
        neighbours.insert(make_pair("left", tmp_key));
    }

    size_t Node::get_neighbour(string direction)
    {
        return neighbours[direction];
    }
}
