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
        pair<int, int> head;
    public:
        Snake();
        Snake(size_t size, pair<int, int> place);
        void move();
        void change_direction(pair<int, int> new_direction);
        size_t get_size();
        pair<int, int> get_tail();
        void set_tail();
        pair<int, int> get_head();
        pair<int, int> part_of_body(size_t i);
    };
}
#endif // SNAKE_H
