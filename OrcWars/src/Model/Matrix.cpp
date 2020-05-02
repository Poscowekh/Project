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

    void Matrix::set_values()
    { //Sets values: 0 = free; 1 = snake, 8 = snake head; 2 = food; 3 = block)
        for(size_t i = 0; i < food.size(); i++)
        { //Food
            matrix[food[i].first][food[i].second] = 2;
        }
        for(size_t i = 0; i < snakes.size(); i++)
        { //Snakes
            if(!growth_check(snakes[i]) && (!destruction_check(snakes[i])))
            {
                for(size_t j = 1; j < snakes[i].get_size(); j++)
                {
                    matrix[snakes[i].part_of_body(j).first][snakes[i].part_of_body(j).second] = 1;
                }
                matrix[snakes[i].get_tail().first][snakes[i].get_tail().second] = 0;
                matrix[snakes[i].get_head().first][snakes[i].get_head().second] = 8;
            }
            if(destruction_check(snakes[i]))
            {
                for(size_t j = 1; j < snakes[i].get_size(); j++)
                    matrix[snakes[i].part_of_body(j).first][snakes[i].part_of_body(j).second] = 1;
                matrix[snakes[i].get_tail().first][snakes[i].get_tail().second] = 0;
                matrix[snakes[i].get_head().first][snakes[i].get_head().second] = 3;
                snakes[i].cut_snake();
            }
            if(snakes[i].get_size() == 0)
            {
                remove_snake(i);
            }
            if(growth_check(snakes[i]))
            {
                remove_food(get_food_id(snakes[i].get_head()));
                snakes[i].grow_snake();
                for(size_t j = 1; j < snakes[i].get_size(); j++)
                    matrix[snakes[i].part_of_body(j).first][snakes[i].part_of_body(j).second] = 1;
                matrix[snakes[i].get_head().first][snakes[i].get_head().second] = 8;
            }
        }
    }

    bool Matrix::destruction_check(Snake snake)
    {
        for(size_t i = 0; i < blocks.size(); i++)
            if(snake.get_head() == blocks[i])
                return true;
    }

    bool Matrix::growth_check(Snake snake)
    {
        for(size_t i = 0; i < food.size(); i++)
            if(snake.get_head() == food[i])
                return true;
    }

    void Matrix::remove_food(size_t apple)
    {
        for(size_t i = apple; i < food.size() - 1; i++)
        {
            food[i] = food[i + 1];
        }
        food.pop_back();
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
    }

    void Matrix::remove_snake(size_t id)
    {
        for(size_t i = id; i < snakes.size() - 1; i++)
        {
            snakes[i] = snakes[i + 1];
        }
        snakes.pop_back();
    }

    size_t Matrix::get_id(Snake snake)
    {
        for(size_t i = 0; i < snakes.size(); i++)
            if(snake.get_head() == snakes[i].get_head())
                return i;
    }

    size_t Matrix::get_food_id(pair<int, int> apple)
    {
        for(size_t i = 0; i < food.size(); i++)
            if(food[i] == apple)
                return i;
    }
}
