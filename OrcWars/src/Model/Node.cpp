// Node.cpp for Model

#include "Node.h"

using namespace std;
namespace GameModel
{
    Node::Node()
    {
        coordinates = make_pair(0,0);
        distance = 0;
        value_in = 0;
        value_out = 0;
        visit_flag = false;
        key = -1;
    }

    Node::Node(pair<int, int> new_coordinates, size_t new_value_in, size_t new_value_out, size_t new_key)
    {
        coordinates = new_coordinates;
        distance = 0;
        value_in = new_value_in;
        value_out = new_value_out;
        visit_flag = false;
        key = new_key;
    }

    pair<int, int> Node::get_coordinates()
    {
        return coordinates;
    }

    pair<int, int> Node::get_values()
    {
        return make_pair(value_in, value_out);
    }

    size_t Node::get_distance()
    {
        return distance;
    }

    size_t Node::get_key()
    {
        return key;
    }

    void Node::set_distance(size_t new_distance)
    {
        distance = new_distance;
    }

    void Node::set_value_in(size_t new_value)
    {
        value_in = new_value;
    }

    void Node::set_value_out(size_t new_value)
    {
        value_out = new_value;
    }

    bool Node::get_visit_flag()
    {
        return visit_flag;
    }

    void Node::mark_as_visited()
    {
        visit_flag = true;
    }

    void Node::add_neighbour(size_t tmp_key)
    {
        neighbours.push_back(tmp_key);
    }

    vector<int> Node::get_neighbours_keys()
    {
        return neighbours;
    }

    size_t Node::get_neighbours_count()
    {
        return neighbours.size();
    }

    void Node::set_way_to(vector<int> way_to_prev)
    {
        way_to = way_to_prev;
        way_to.push_back(key);
    }

    vector<int> Node::get_way_to()
    {
        return way_to;
    }
}
