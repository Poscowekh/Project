#include "oxygine-framework.h"
#include <functional>
#include "ViewHelper.h"
#include "Model/Matrix.h"
#include "Model/Tests.h"
#include "Presenter/Game_presenter.h"

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

    //GameModel::test_circle();             //Test circle movement
    //GameModel::test_food();               //Test eating food
    //GameModel::test_block();              //Test reaching block
    //GameModel::test_food_block();         //Test eating food and reaching block

    //GameModel::test_border();             //Test destroying at border
    //GameModel::test_border_food();        //Test eating food at border
    //GameModel::test_border_block();       //Test destroying by block at border
    //GameModel::test_border_food_block();  //Test eating and destroying at border
    
    Vector2 a(10, 10);
    size_t b = 10;
    spGame_presenter presenter = new Game_presenter(a, b);
    presenter->show(getStage());

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
