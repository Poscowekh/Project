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
    public:
        vector< pair<int, int> > body;
        Snake();
        Snake(int size, pair<int, int> head);
        void snake_move(pair<int, int> direction);
        size_t get_size();
    };
    #endif // SNAKE_H
}
