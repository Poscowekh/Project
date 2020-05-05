//Food.cpp fo Food

#include "Food.h"

namespace GameModel
{
using namespace std;
    Food::Food(size_t new_id, pair<int, int> new_coordinates, string new_type/*, size_t new_growth_value*/)
    { //Creates Food at random coordinates of some type and gives it an id
        coordinates = new_coordinates;
        id = new_id;
        type = new_type;
        //growth value = new_growth_value;
    }

    pair<int, int> Food::get_coordinates()
    {
        return this->coordinates;
    }

    size_t Food::get_id()
    {
        return this->id;
    }

    string Food::get_type()
    {
        return this->type;
    }

    /*size_t Food::get_growth_value()
    {
        return this->growth_value;
    }*/
}
