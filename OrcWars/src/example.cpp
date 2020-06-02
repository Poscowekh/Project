#include "oxygine-framework.h"
#include <functional>
#include "ViewHelper.h"
#include "Model/Matrix.h"
#include "Model/Graph.h"
#include "Model/Tests.h"
#include "Presenter/Game_presenter.h"
#include "Menu/Menu.h"
#include <iostream>

using namespace oxygine;
//it is our resources
//in real project you would have more than one Resources declarations.
//It is important on mobile devices with limited memory and you would load/unload them
Resources gameResources;

//GameState *st;

using namespace GameModel;
using namespace GameGraphics;

Resources ViewHelper::res;
GameGraphics::spGame_presenter presenter;
GameGraphics::spMenu menu;
bool start_flag = false;        //if true game started game should start or not
bool stop_flag = false;         //if true game is exited
int cnt = 0;

void example_preinit() {}

//called from main.cpp
void example_init()
{
    Point display_size = core::getDisplaySize();
    ViewHelper::res.loadXML("res.xml");
    /*st = new GameState();

    //GameModel::test_circle();             //Test circle movement
    //GameModel::test_food();               //Test eating food
    //GameModel::test_block();              //Test reaching block
    //GameModel::test_food_block();         //Test eating food and reaching block

    //GameModel::test_border();             //Test destroying at border
    //GameModel::test_border_food();        //Test eating food at border
    //GameModel::test_border_block();       //Test destroying by block at border
    //GameModel::test_border_food_block();  //Test eating and destroying at border*/

    //getStage()->addChild(st);

    /*getStage()->addTween(TweenDummy(), 1000)->setDoneCallback([&presenter](Event * )
    {*/
    display_size = core::getDisplaySize();
    presenter = new Game_presenter(display_size, 0, make_pair(0,0));
    presenter->show(getStage());
    //}
    //);
    menu = new Menu(display_size);
    menu->show_start_button(getStage());
}

//called each frame from main.cpp
void example_update()
{
    start_flag = menu->get_start_flag();
    if(start_flag)
    {
        presenter->set_field(menu->return_field_x(), menu->return_field_y());
        menu->update_timer(getStage());
        menu->show_timer(getStage());
        menu->hide_start_button(getStage());
        if(cnt % 40 == 0)              //frames per tick
        {
            presenter->update(getStage());
            cnt = 0;
        }
        cnt++;
    }
    //else
        //
    //st->update();
}

//called each frame from main.cpp
void example_destroy()
{
    //st->~GameState();
    //free previously loaded resources
}
