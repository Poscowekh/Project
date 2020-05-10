//Game_presenter.cpp for Graphics

#include "Game_presenter.h"
#include <iostream>

namespace GameGraphics
{
    Game_presenter::Game_presenter(Point display_size, size_t players_cnt, pair<int, int> new_position, GameModel::spMatrix mtrx)
    {
        int size_shift = 80;
        matrix = mtrx;
        size = display_size;
        position = new_position;
        //float scale_factor_x = (display_size.x - 40) / display_size.x;
        //float scale_factor_y = (display_size.y - 40) / display_size.y;

        pair<int, int> view_pos = make_pair(size_shift / 2, size_shift / 2);

        view = new Game_view(Vector2(display_size.x - size_shift, display_size.y - size_shift), view_pos, matrix);
    }

    void Game_presenter::show(oxygine::spActor actor)
    {
        view->update_view();
        actor->addChild(view);
    }

    void Game_presenter::hide()
    {

    }
}
//Game_view(Vector2 new_size, int new_color, pair<int, int> new_position)
