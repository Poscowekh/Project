// Snake.cpp for Snake

#include "Snake.h"

namespace GameModel
{
using namespace std;

    Snake::Snake()
    {//Creates Snake at (0,0)
        body.push_back(make_pair(0,0));
        tail = body[0];
    }

    Snake::Snake(size_t size, pair<int, int> place)
    { //Creates Snake of size at (x,y) !!vertically, (! = head)
        body.resize(size);
        head = place;
        for (size_t i = 0; i < size; i++)
        {
            body[i] = make_pair(place.first + i, place.second);
        }
        tail = body[size - 1];
        movement_vector = (make_pair(1,0));
    }

    size_t Snake::get_size()
    {
        return this->body.size();
    }

    void Snake::change_direction(pair<int, int> new_direction)
    { //Changes Snake's movement direction
        if(!((new_direction.first == -movement_vector.first) && (new_direction.first == -movement_vector.first))) //Shouldn't move in itself
            movement_vector = new_direction;
    }

    void Snake::move()
    { //Moves Snake in predefined direction [x,y]
        tail = body.back();
        for (size_t i = 1; i < body.size(); i++)
        {
            body[i].first = body[i - 1].first;
            body[i].second = body[i - 1].second;
        }
        body[0].first = get_head().first + movement_vector.second;
        body[0].second = get_head().second + movement_vector.first;
        head = body.front();
    }

    pair<int, int> Snake::part_of_body(size_t i)
    { //Returns coordinates of body part
        return this->body[i];
    }

    pair<int, int> Snake::get_tail()
    { //Returns coordinates of tail
        return this->tail;
    }

    void Snake::set_tail()
    { //Resets coordinates of tail
        tail = body[get_size() - 1];
    }

    pair<int, int> Snake::get_head()
    { //Returns coordinates of head
        return this->head;
    }
}
