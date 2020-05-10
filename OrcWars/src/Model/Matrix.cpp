// Matrix.cpp for Model

#include "Matrix.h"

using namespace std;
namespace GameModel
{
    Matrix::Matrix()
    { //Creates default matrix 10x10
        rows = 10;
        columns = 10;
        matrix.resize(rows);
        for (size_t i = 0; i < rows; i++) {
            matrix[i].resize(columns, 0);
        }
    }

    Matrix::Matrix(size_t m, size_t n)
    { //Creates matrix m by n
        rows = m;
        columns = n;
        matrix.clear();
        matrix.resize(rows);
        for (size_t i = 0; i < rows; i++)
            matrix[i].resize(columns, 0);
        food.clear();
        snakes.clear();
        blocks.clear();
        start_movement_flag = false;
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
        cout << "Field:" << endl;
        for (size_t i = 0; i < get_rows(); i++)
        {
            for (size_t j=0; j < get_columns(); j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void Matrix::reset_matrix()
    {
        for(size_t i = 1; i < rows - 1; i++)
            for(size_t j = 1; j < columns - 1; j++)
                matrix[i][j] = 0;
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

    pair<int, int> Matrix::get_random_coordinates(size_t seed)
    {
        srand(seed);
        int x = rand() % get_columns();
        int y = rand() % get_rows();
        return make_pair(x, y);
    }

    pair<int, int> Matrix::get_random_free_coordinates(size_t seed)
    {
        pair<int, int> tmp = get_random_coordinates(seed);
        while(!check_cell(tmp))
        {
            seed++;
            tmp = get_random_coordinates(seed);
        }
        return tmp;
    }

    size_t Matrix::get_new_id_snake()
    {
        new_id_snake++;
        return new_id_snake;
    }

    size_t Matrix::get_new_id_food()
    {
        new_id_food++;
        return new_id_food;
    }

    size_t Matrix::get_new_id_block()
    {
        new_id_block++;
        return new_id_block;
    }

    void Matrix::spawn_food(string new_type, pair<int, int> new_coordinates, size_t new_id)
    { //Spawns food in the cell
        Food tmp = Food(new_id, new_coordinates, new_type);
        food.push_back(tmp);
    }

    void Matrix::spawn_block(string new_type, pair<int, int> new_coordinates, size_t new_id)
    { //Spawns block in a random free cell
        Block tmp = Block(new_id, new_coordinates, new_type);
        blocks.push_back(tmp);
    }

    void Matrix::spawn_borderline()
    { //Spawns block in a random free cell
        for(size_t i = 0; i < columns; i++)
        {
            Block tmp = Block(0, make_pair(0,i), "mountains");
            blocks.push_back(tmp);
        }
        for(size_t i = 0; i < columns; i++)
        {
            Block tmp = Block(0, make_pair(rows - 1,i), "mountains");
            blocks.push_back(tmp);
        }
        for(size_t i = 1; i < rows - 1; i++)
        {
            Block tmp = Block(0, make_pair(i,0), "mountains");
            blocks.push_back(tmp);
        }
        for(size_t i = 1; i < rows - 1; i++)
        {
            Block tmp = Block(0, make_pair(i,columns - 1), "mountains");
            blocks.push_back(tmp);
        }
    }

    void Matrix::update_matrix()
    { //Sets values: 0 = free; 1 = snake, 8 = snake head; 2 = food; 3 = block)
        reset_matrix();
        if(start_movement_flag && snakes.size() > 0)
            move_snakes();
        else
            start_movement_flag = true;
        for(size_t i = 0; i < food.size(); i++)
            matrix[food[i].get_coordinates().first][food[i].get_coordinates().second] = 2;
        for(size_t i = 0; i < blocks.size(); i++)
            matrix[blocks[i].get_coordinates().first][blocks[i].get_coordinates().second] = 3;
        for(size_t i = 0; i < snakes.size(); i++)
        {
            bool grow = false;
            if(growth_check(snakes[i]))
                grow = true;
            bool destroy = false;
            if(destruction_check(snakes[i]))
                destroy = true;
            for(size_t j = 1; j < snakes[i].get_size(); j++)
                matrix[snakes[i].part_of_body(j).first][snakes[i].part_of_body(j).second] = 1;
            if(grow)
            {
               snakes[i].grow_snake();
               remove_food(snakes[i].get_head());
               matrix[snakes[i].get_tail().first][snakes[i].get_tail().second] = 1;
            }
            if(!destroy)
                matrix[snakes[i].get_head().first][snakes[i].get_head().second] = 8;
            else
            {
                matrix[snakes[i].get_tail().first][snakes[i].get_tail().second] = 0;
                if(snakes[i].get_size() > 1)
                {
                    matrix[snakes[i].get_head().first][snakes[i].get_head().second] = 3;
                    snakes[i].cut_snake();
                }
                else
                {
                    matrix[snakes[i].get_head().first][snakes[i].get_head().second] = 3;
                    remove_snake(get_snake_id(snakes[i]));
                }
            }
        }
    }

    bool Matrix::destruction_check(Snake snake)
    {
        bool tmp;
        for(size_t i = 0; i < blocks.size(); i++)
            if(snake.get_head() == blocks[i].get_coordinates())
                tmp = true;
        if(tmp)
            return true;
        else
            return false;
    }

    bool Matrix::growth_check(Snake snake)
    {
        bool tmp;
        for(size_t i = 0; i < food.size(); i++)
            if(snake.get_head() == food[i].get_coordinates())
                tmp = true;
        if(tmp)
            return true;
        else
            return false;

    }

    void Matrix::remove_food(pair<int, int> coordinates)
    {
        for(size_t i = 0; i < food.size(); i++)
            if(food[i].get_coordinates() == coordinates)
            {
                food[i] = food[food.size() - 1];
                food.pop_back();
            }
    }

    void Matrix::change_movement(size_t id, pair<int, int> movement)
    { //Changes snake id's movement vector
        snakes[return_snakes_index_by_id(id)].change_direction(movement);
    }

    void Matrix::add_snake(size_t new_size, pair<int, int> head, size_t new_id)
    {
        Snake tmp = Snake(new_size, head, new_id);
        snakes.push_back(tmp);
    }

    void Matrix::remove_snake(size_t index)
    {
        snakes[index] = snakes[snakes.size() - 1];
        snakes.pop_back();
    }

    size_t Matrix::get_snake_id(Snake snake)
    {
        return snake.get_id();
    }

    size_t Matrix::return_snakes_index_by_id(size_t id)
    {
        int index;
        for(size_t i = 0; i < snakes.size(); i++)
            if(snakes[i].get_id() == id)
                index = i;
        return index;
    }

    size_t Matrix::get_food_id(pair<int, int> coordinates)
    {
        for(size_t i = 0; i < food.size(); i++)
            if(food[i].get_coordinates() == coordinates)
                return food[i].get_id();
    }

    size_t Matrix::get_block_id(pair<int, int> coordinates)
    {
        for(size_t i = 0; i < blocks.size(); i++)
            if(blocks[i].get_coordinates() == coordinates)
                return blocks[i].get_id();
    }

    vector<Block> Matrix::get_blocks()
    {
        return blocks;
    }

    vector<Food> Matrix::get_food()
    {
        return food;
    }

    vector<Snake> Matrix::get_snakes()
    {
        return snakes;
    }

    size_t Matrix::get_value(pair<int, int> coordinates)
    {
        return matrix[coordinates.first][coordinates.second];
    }

    pair<int, int> Matrix::get_snake_head(size_t id)
    {
        return snakes[return_snakes_index_by_id(id)].get_head();
    }

    size_t Matrix::get_food_count()
    {
        return food.size();
    }

    size_t Matrix::get_blocks_count()
    {
        return blocks.size();
    }
}
