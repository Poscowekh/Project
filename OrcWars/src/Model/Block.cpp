//Block.cpp fo Block

#include "Block.h"

namespace GameModel
{
using namespace std;
    Block::Block(size_t new_id, pair<int, int> new_coordinates, string new_type)
    { //Creates Block of size at random coordinates of some type and gives it an id
        coordinates = new_coordinates;
        id = new_id;
        type = new_type;
    }

    pair<int, int> Block::get_coordinates()
    {
        return this->coordinates;
    }

    size_t Block::get_id()
    {
        return this->id;
    }

    string Block::get_type()
    {
        return this->type;
    }
}
