// Snake.cpp for Snake

#include "Snake.h"

namespace GameModel
{
using namespace std;

    Snake::Snake()
    {
        body.push_back(make_pair(0,0));
    }

    Snake::Snake(size_t size, pair<int, int> head)
    { //Creates Snake of size at x,y_
        body.resize(size);
        for (size_t i = 0; i < size; i++)
        {
            body[i] = make_pair(head.first + i, head.second);
        }
    }

    size_t Snake::get_size()
    {
        return this->body.size();
    }

    void Snake::snake_move(pair<int, int> direction)
    { //Moves Snake one block in direction
        for (int i = 0; i < (int)body.size(); i++)
        {
            body[i].first = direction.first;
            body[i].second = direction.second;
        }
    }
}
