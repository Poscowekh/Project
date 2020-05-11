#include "oxygine-framework.h"
#include <functional>
#include "ViewHelper.h"
#include "Model/Matrix.h"
#include "Model/Graph.h"
#include "Model/Tests.h"
#include "Presenter/Game_presenter.h"
#include <iostream>

using namespace oxygine;
//it is our resources
//in real project you would have more than one Resources declarations.
//It is important on mobile devices with limited memory and you would load/unload them
Resources gameResources;

//GameState *st;

using namespace GameModel;
using namespace GameGraphics;

void example_preinit() {}

Resources ViewHelper::res;
GameGraphics::spGame_presenter presenter;
int cnt = 0;

//called from main.cpp
void example_init()
{
    srand(time(NULL));
    ViewHelper::res.loadXML("data/res.xml");

    //st = new GameState();

    //GameModel::test_circle();             //Test circle movement
    //GameModel::test_food();               //Test eating food
    //GameModel::test_block();              //Test reaching block
    //GameModel::test_food_block();         //Test eating food and reaching block

    //GameModel::test_border();             //Test destroying at border
    //GameModel::test_border_food();        //Test eating food at border
    //GameModel::test_border_block();       //Test destroying by block at border
    //GameModel::test_border_food_block();  //Test eating and destroying at border
    

    //GameModel::Graph graph(field->get_snake_head(0), field);
    //graph.create_map();
    //graph.Dijkstra();

    //getStage()->addChild(st);

    Point display_size = core::getDisplaySize();
    presenter = new Game_presenter(display_size, 0, make_pair(0,0));

}


//called each frame from main.cpp
void example_update()
{
    if(cnt % 100 == 0)
    {
        presenter->update();
        cnt = 0;
    }
    cnt++;
    //st->update();
}

//called each frame from main.cpp
void example_destroy()
{
    //st->~GameState();
    //free previously loaded resources
}
