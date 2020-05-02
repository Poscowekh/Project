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

     //srand(time(NULL));
    srand(1);
    int x = 7;
    int y = 5;
    //cin >> x >> y;
    GameModel::Matrix field = GameModel::Matrix(x, y); //Matrix x by y
    field.add_snake(3, make_pair(2,2));  //Snake of size 3 at x(2-2),y(2-4)
    field.spawn_food(1);
    field.spawn_blocks(2);
    field.print();
    field.move_snakes();
    field.set_values();
    field.print();
    
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
