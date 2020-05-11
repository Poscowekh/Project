//Game_presenter.cpp for Graphics

#include "Game_presenter.h"
#include <iostream>

namespace GameGraphics
{
    Game_presenter::Game_presenter(Point display_size, size_t players_cnt, pair<int, int> new_position, GameModel::spMatrix mtrx)
    {
        //int size_shift = 80;
        matrix = mtrx;
        size = display_size;
        position = new_position;
        //float scale_factor_x = (display_size.x - 40) / display_size.x;
        //float scale_factor_y = (display_size.y - 40) / display_size.y;
    }

    void Game_presenter::init_view()
    {
        int size_shift = 80;
        pair<int, int> view_pos = make_pair(size_shift / 2, size_shift / 2);
        view = new Game_view(Vector2(size.x - size_shift, size.y - size_shift), view_pos, matrix);
    }

    void Game_presenter::update()
    {
        matrix->update_matrix();
        matrix->print();
        view->update();
        show(getStage());
    }

    void Game_presenter::count_update()
    {
        for(size_t i = 0; i < 3; i++)
        {
            update();
        }
    }

    void Game_presenter::show(oxygine::spActor actor)
    {
        actor->addChild(view);
    }

    void Game_presenter::hide()
    {
    }
}
//Game_view(Vector2 new_size, int new_color, pair<int, int> new_position)
