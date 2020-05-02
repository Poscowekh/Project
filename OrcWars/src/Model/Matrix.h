// Matrix.h for Matrix

#ifndef SNAKE_GAME_MATRIX_H
#define SNAKE_GAME_MATRIX_H
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Snake.h"
#include <random>
#include <time.h>
using namespace std;
namespace GameModel
{
    class Matrix
    {
    private:
        size_t rows;
        size_t columns;
        vector< vector<int> > matrix;   //The field
        vector<Snake > snakes;          //All snakes
        vector<pair<int, int> > food;   //All food
        vector<pair<int, int> > blocks; //All blocks
        vector<int> ignore;             //Snakes that grow this tick (by id)
    public:
        Matrix();
        Matrix(int, int);
        int& operator()(const int &row, const int &col);
        size_t get_rows();
        size_t get_columns();
        bool check_cell(pair<int, int>);

        //for snakes
        void move_snakes();
        void change_movement(size_t id, pair<int, int> movement);
        void add_snake(size_t size, pair<int, int> head);
        void destruction_check(Snake snake);

        //for food and blocks
        void spawn_food(size_t n);
        void spawn_blocks(size_t n);

        //for printing matrix
        void reload();
        void set_values();
        void print();
    };
}
#endif // MATRIX_H
