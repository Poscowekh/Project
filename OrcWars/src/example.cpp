#include "oxygine-framework.h"
#include <functional>
#include "ViewHelper.h"
#include "Model/Matrix.h"
#include "Model/Snake.h"

using namespace oxygine;
//it is our resources
//in real project you would have more than one Resources declarations.
//It is important on mobile devices with limited memory and you would load/unload them
Resources gameResources;

//GameState *st;

using namespace GameModel;

void example_preinit() {}

Resources ViewHelper::res;

//called from main.cpp
void example_init()
{
    ViewHelper::res.loadXML("res.xml");

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
    
    //st = new GameState();
    //getStage()->addChild(st);

}


//called each frame from main.cpp
void example_update()
{
    //st->update();
}

//called each frame from main.cpp
void example_destroy()
{
    //st->~GameState();
    //free previously loaded resources
}
