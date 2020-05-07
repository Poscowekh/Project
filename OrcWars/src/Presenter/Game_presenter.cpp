#include "Game_presenter.h"

Game_presenter::Game_presenter(oxygine::Vector2 size, size_t players_cnt)
{
    view = new Game_view;
    matrix = new GameModel::Matrix;
}

void Game_presenter::show(oxygine::spActor actor)
{

}

void Game_presenter::hide()
{

}
