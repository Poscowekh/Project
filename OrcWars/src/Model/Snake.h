// Snake.h for Snake

#ifndef SNAKE_H
#define SNAKE_H
#include <stdlib.h>
#include <vector>
#include <utility>
#include <string>
using namespace std;
namespace GameModel
{


    class Snake {
    private:
        pair<int, int> movement_vector;
        vector< pair<int, int> > body;
        pair<int, int> tail;
        size_t id;
        size_t size;
    public:
        Snake(size_t new_id);
        Snake(size_t new_size, pair<int, int> place, size_t new_id);
        void set_tail();
        size_t get_size();
        size_t get_id();
        void set_id(size_t new_id);
        pair<int, int> get_tail();
        pair<int, int> get_head();
        pair<int, int> part_of_body(size_t i);
        void move();
        void change_direction(pair<int, int> new_direction);
        void cut_snake();
        void grow_snake();
        void add_to_snake(pair<int, int> new_part);
    };
}
#endif // SNAKE_H
