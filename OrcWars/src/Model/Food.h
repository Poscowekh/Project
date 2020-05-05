//Food.h for Food

#ifndef FOOD_H
#define FOOD_H
#include <stdlib.h>
#include <utility>
#include <string>
using namespace std;
namespace GameModel
{
    class Food
    {
        private:
            size_t id;
            pair<int, int> coordinates;
            string type;                //Apple, rabbit, etc
            //size_t growth_value;      //May be useful in future
        public:
            Food(size_t new_id, pair<int, int> new_coordinates, string new_type/*size_T new_growth_value*/);
            string get_type();
            size_t get_id();
            pair<int, int> get_coordinates();
    };
}
#endif // FOOD_H
