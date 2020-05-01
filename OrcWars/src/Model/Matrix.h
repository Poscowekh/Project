// matrix.h

#ifndef SNAKE_GAME_MATRIX_H
#define SNAKE_GAME_MATRIX_H

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;
namespace GameModel
{
    class Matrix
    {
    private:
        size_t rows;
        size_t columns;
    public:
        vector< vector<int> > matrix;
        Matrix();
        Matrix(int, int);
        int& operator()(const int &, const int &);
        int getRows() const;
        int getCols() const;
        void print() const;
    };
}
#endif // MATRIX_H
