// Matrix.cpp for Matrix

#include "Matrix.h"

using namespace std;
namespace GameModel
{
    Matrix::Matrix()
    {//Creates default matrix 5x5
        rows = 5;
        columns = 5;
        matrix.resize(columns);
        for (int i = 0; i < columns; i++) {
            matrix[i].resize(rows, 0);
        }
    }

    Matrix::Matrix(int x, int y)
    {//Creates matrix x by y
        rows = y;
        columns = x;
        matrix.resize(rows);
        for (size_t i = 0; i < rows; i++)
        {
            matrix[i].resize(columns);
        }
    }

    int& Matrix::operator()(const int &row, const int &column)
    {//Returns value
        return this->matrix[row][column];
    }

    size_t Matrix::get_rows()
    {
        return this->rows;
    }

    size_t Matrix::get_columns()
    {
        return this->columns;
    }

    void Matrix::print()
    { //Prints matrix
        cout << "Field: " << endl;
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j=0; j < columns; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool Matrix::check_cell(pair<int, int> coordinates)
    { //Returns true if cell is occupied
        if(matrix[coordinates.first][coordinates.second] != 0)
        {
            return true;
        } else {
            return false;
        }
    }

    void Matrix::move_snakes()
    { //Initiates movement of all snakes
        for(size_t i = 0; i < snakes.size(); i++)
        {
            snakes[i].move();
        }

    }

    void Matrix::spawn_food(size_t n)
    { //Spawns food in n random free cells
        for(size_t i = 0; i < n; i++)
        {
            pair<int, int> tmp = make_pair(rand() % get_rows(), rand() % get_columns());
            while(check_cell(tmp))
            {
                pair<int, int> tmp = make_pair(rand() % get_rows(), rand() % get_columns());
            }
            food.push_back(tmp);
            matrix[tmp.first][tmp.second] = 2;
        }
    }

    void Matrix::spawn_blocks(size_t n)
    { //Spawns n blocks in random free cell
        for(size_t i = 0; i < n; i++)
        {
            pair<int, int> tmp = make_pair(rand() % get_rows(), rand() % get_columns());
            while(check_cell(tmp))
            {
                pair<int, int> tmp = make_pair(rand() % get_rows(), rand() % get_columns());
            };
            blocks.push_back(tmp);
            matrix[tmp.first][tmp.second] = 3;
        }
    }

    /*void Matrix::reload()
    { //Sets matrix to 0 values
        for(size_t i = 0; i < rows; i++)
        {
            for(size_t j = 0; j < columns; i++)
            {
                matrix[i][j] = 0;
            }
        }
    }*/

    void Matrix::set_values()
    { //Sets values: 0 = free; 1 = snake; 2 = food; 3 = block)
        for(size_t i = 0; i < food.size(); i++)
        { //Food
            matrix[food[i].first][food[i].second] = 2;
        }/*
        for(size_t i = 0; i < blocks.size(); i++)
        { //Blocks
            matrix[blocks[i].first][blocks[i].second] = 3;
        }*/
        for(size_t i = 0; i < snakes.size(); i++)
        { //Snakes
            for(size_t j = 0; j < snakes[i].get_size(); j++)
            {
                matrix[snakes[i].part_of_body(j).first][snakes[i].part_of_body(j).second] = 1;
            }
            matrix[snakes[i].get_head().first][snakes[i].get_head().second] = 8;
            matrix[snakes[i].get_tail().first][snakes[i].get_tail().second] = 0;
            snakes[i].set_tail();
        }
    }

    void Matrix::destruction_check(Snake snake)
    {

    }

    void Matrix::change_movement(size_t id, pair<int, int> movement)
    { //Changes snake id's movement vector
        snakes[id].change_direction(movement);
    }

    void Matrix::add_snake(size_t size, pair<int, int> head)
    {
        Snake tmp = Snake(size, head);
        for(size_t i = 0; i < size; i++)
        {
            matrix[tmp.part_of_body(i).first][tmp.part_of_body(i).second] = 1;
        }
        matrix[tmp.get_head().first][tmp.get_head().second] = 8; //head = 8
        snakes.push_back(tmp);
        //ignore.push_back(tmp); ?
    }
}
