// main.cpp

#include "Matrix.h"
#include "Snake.h"
#include "Food.h"
#include "Block.h"

using namespace std;

int main() {
    int m = 5;
    int n = 9;
    //cin >> x >> y;
    GameModel::Matrix field = GameModel::Matrix(m, n); //Matrix m rows by n columns
    field.spawn_food("apple", make_pair(1,2), 0);
    field.spawn_block("wall", make_pair(1,6), 1);
    field.update_matrix();
    field.print();
    field.add_snake(2, make_pair(1,4), 0);             //Snake of size 2 at row 1 and column 4
    field.change_movement(0, make_pair(0,-1));         //Moves left
    for(size_t i = 0; i < 2; i++)
    {
        field.update_matrix();
        field.print();
    }
    field.change_movement(0, make_pair(1,0));         //Moves down
    field.update_matrix();
    field.print();
    field.change_movement(0, make_pair(0,1));         //Moves right
    for(size_t i = 0; i < 4; i++)
    {
        field.update_matrix();
        field.print();
    }
    field.change_movement(0, make_pair(-1,0));         //Moves up
    for(size_t i = 0; i < 2; i++)
    {
        field.update_matrix();
        field.print();
    }
    return 0;
}
