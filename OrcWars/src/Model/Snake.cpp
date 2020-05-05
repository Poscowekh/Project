// Snake.cpp for Snake

#include "Snake.h"

namespace GameModel
{
using namespace std;

    Snake::Snake(size_t new_id)
    {//Creates Snake at (0,0)
        body.push_back(make_pair(0,0));
        tail = body[0];
        size = 1;
        id = new_id;
    }

    Snake::Snake(size_t new_size, pair<int, int> place, size_t new_id)
    { //Creates Snake of size at (x,y) !!vertically head at place tail up
        body.resize(new_size);
        size = new_size;
        for (size_t i = 0; i < size; i++)
            body[i] = make_pair(place.first - i, place.second);
        tail = body[size - 1];
        movement_vector = (make_pair(0,-1)); //By default moves left
        id = new_id;
        set_tail();
    }

    size_t Snake::get_size()
    {
        return this->size;
    }

    size_t Snake::get_id()
    {
        return this->id;
    }

    pair<int, int> Snake::get_tail()
    { //Returns coordinates of tail
        return this->tail;
    }

    void Snake::set_tail()
    { //Resets coordinates of tail
        tail = body[get_size() - 1];
    }

    void Snake::set_id(size_t new_id)
    {
        id = new_id;
    }

    pair<int, int> Snake::get_head()
    { //Returns coordinates of head
        return body[0];
    }

    void Snake::change_direction(pair<int, int> new_direction)
    { //Changes Snake's movement direction
        if(get_size() > 1)  //Shouldn't move to itself!
        {
            if((get_head().first + new_direction.first != part_of_body(1).first) && (get_head().second + new_direction.second != part_of_body(1).second))
                movement_vector = new_direction;
        }
        else
                movement_vector = new_direction;
    }

    void Snake::move()
    { //Moves Snake in predefined direction [x,y]
        set_tail();
        for (size_t i = 1; i < body.size(); i++)
        {
            body[i].first = body[i - 1].first;
            body[i].second = body[i - 1].second;
        }
        body[0].first = get_head().first + movement_vector.first;
        body[0].second = get_head().second + movement_vector.second;
    }

    pair<int, int> Snake::part_of_body(size_t i)
    { //Returns coordinates of body part
        return this->body[i];
    }

    void Snake::cut_snake()
    {
        for(size_t i = 0; i < get_size() - 1; i++)
            body[i] = body[i + 1];
        body.pop_back();
    }

    void Snake::grow_snake()
    {
        body.push_back(get_tail());
    }

    void Snake::add_to_snake(pair<int, int> new_part)
    {
        body.push_back(new_part);
    }
}
