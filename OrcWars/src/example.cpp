#include "oxygine-framework.h"
#include <functional>
#include "ViewHelper.h"

using namespace oxygine;
//it is our resources
//in real project you would have more than one Resources declarations.
//It is important on mobile devices with limited memory and you would load/unload them
Resources gameResources;

//GameState *st;


void example_preinit() {}

Resources ViewHelper::res;

//called from main.cpp
void example_init()
{
    ViewHelper::res.loadXML("res.xml");

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
