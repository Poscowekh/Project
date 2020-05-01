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

    int x = 5;
    int y = 5;
    //cin >> x >> y;
    GameModel::Matrix field = GameModel::Matrix(x, y);
    field.print();
    GameModel::Snake viper  = GameModel::Snake();
    for(size_t i = 0; i < viper.body.size(); ++ i) {
        field.matrix[viper.body[i].first][viper.body[i].second] = 1;
    };
    field.print();
    viper.snake_move(make_pair(1,0));
    for(int i = 0; i < (int)viper.body.size(); i++) {
        field.matrix[viper.body[i].first][viper.body[i].second] = 1;
    };
    field.print();
    std:cout << viper.body.size();

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
