// Tests.cpp for Model

#include "Tests.h"

using namespace std;
namespace GameModel
{
    void test_food()
    {
        int m = 3;
        int n = 7;
        GameModel::Matrix field = GameModel::Matrix(m, n); //Matrix m rows by n columns
        field.spawn_borderline();
        field.add_snake(2, make_pair(1,2), 0);             //Snake of size 2 at (1,1)
        field.spawn_food("apple", make_pair(1,4), 1);
        field.change_movement(0, make_pair(0,1));          //Moves right 3 times
        for(size_t i = 0; i < 4; i++)
        {
            field.update_matrix();
            field.print();
        }
    }

    void test_block()
    {
        int m = 3;
        int n = 7;
        GameModel::Matrix field = GameModel::Matrix(m, n); //Matrix m rows by n columns
        field.spawn_borderline();
        field.add_snake(2, make_pair(1,2), 0);             //Snake of size 2 at (1,1)
        field.spawn_block("wall", make_pair(1,4), 1);
        field.change_movement(0, make_pair(0,1));          //Moves right 3 times
        for(size_t i = 0; i < 4; i++)
        {
            field.update_matrix();
            field.print();
        }
    }

    void test_food_block()
    {
        int m = 3;
        int n = 8;
        GameModel::Matrix field = GameModel::Matrix(m, n); //Matrix m rows by n columns
        field.spawn_borderline();
        field.add_snake(2, make_pair(1,2), 0);             //Snake of size 2 at (1,1)
        field.spawn_food("apple", make_pair(1,4), 1);
        field.spawn_block("wall", make_pair(1,5), 2);
        field.change_movement(0, make_pair(0,1));          //Moves right 4 times
        for(size_t i = 0; i < 6; i++)
        {
            field.update_matrix();
            field.print();
        }
    }

    void test_circle()
    {
        int m = 5;
        int n = 5;
        GameModel::Matrix field = GameModel::Matrix(m, n); //Matrix m rows by n columns
        field.spawn_borderline();
        field.add_snake(2, make_pair(1,2), 0);             //Snake of size 2 at (1,1)
        field.change_movement(0, make_pair(0,1));         //Moves right 1 time
        for(size_t i = 0; i < 2; i++)
        {
            field.update_matrix();
            field.print();
        }
        field.change_movement(0, make_pair(1,0));         //Moves down 2 times
        for(size_t i = 0; i < 2; i++)
        {
            field.update_matrix();
            field.print();
        }
        field.change_movement(0, make_pair(0,-1));         //Moves left 2 times
        for(size_t i = 0; i < 2; i++)
        {
            field.update_matrix();
            field.print();
        }
        field.change_movement(0, make_pair(-1,0));         //Moves up 2 times
        for(size_t i = 0; i < 2; i++)
        {
            field.update_matrix();
            field.print();
        }
    }

    void test_border()
    {
        int m = 3;
        int n = 6;
        GameModel::Matrix field = GameModel::Matrix(m, n); //Matrix m rows by n columns
        field.spawn_borderline();
        field.add_snake(3, make_pair(1,3), 0);             //Snake of size 2 at (1,1)
        field.change_movement(0, make_pair(0,1));          //Moves right 4 times
        for(size_t i = 0; i < 5; i++)
        {
            field.update_matrix();
            field.print();
        }
    }

    void test_border_food()
    {
        int m = 3;
        int n = 7;
        GameModel::Matrix field = GameModel::Matrix(m, n); //Matrix m rows by n columns
        field.spawn_borderline();
        field.add_snake(2, make_pair(1,2), 0);             //Snake of size 2 at (1,1)
        field.spawn_food("apple", make_pair(1,5), 1);
        field.change_movement(0, make_pair(0,1));          //Moves right 4 times
        for(size_t i = 0; i < 7; i++)
        {
            field.update_matrix();
            field.print();
        }
    }

    void test_border_block()
    {
        int m = 3;
        int n = 6;
        GameModel::Matrix field = GameModel::Matrix(m, n); //Matrix m rows by n columns
        field.spawn_borderline();
        field.add_snake(2, make_pair(1,2), 0);             //Snake of size 2 at (1,1)
        field.spawn_block("wall", make_pair(1,4), 1);
        field.change_movement(0, make_pair(0,1));          //Moves right 4 times
        for(size_t i = 0; i < 4; i++)
        {
            field.update_matrix();
            field.print();
        }
    }

    void test_border_food_block()
    {
        int m = 3;
        int n = 8;
        GameModel::Matrix field = GameModel::Matrix(m, n); //Matrix m rows by n columns
        field.spawn_borderline();
        field.add_snake(2, make_pair(1,2), 0);             //Snake of size 2 at (1,1)
        field.spawn_food("apple", make_pair(1,5), 1);
        field.spawn_food("apple", make_pair(1,7), 1);
        field.change_movement(0, make_pair(0,1));          //Moves right 4 times
        for(size_t i = 0; i < 9; i++)
        {
            field.update_matrix();
            field.print();
        }
    }
}
