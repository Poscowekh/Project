#include "Game_presenter.h"

namespace GameGraphics
{
    Game_presenter::Game_presenter(oxygine::Vector2 size, size_t players_cnt, GameModel::spMatrix mtrx, pair<int, int> new_position)
    {
        matrix = mtrx;
        position = new_position;
        view = new Game_view(size, 0x00FF002F, position);
    }

    void Game_presenter::show(oxygine::spActor actor)
    {
        actor->addChild(view);
    }

    void Game_presenter::hide()
    {

    }

    void Game_presenter::draw_matrix()
    {
        spGame_view child;
        for(size_t i = 0; i < matrix->get_rows(); i++)
            for(size_t j = 0; j < matrix->get_columns(); j++)
            {
                if(matrix->get_value(make_pair(i,j)) == 1)
                    child = new Game_view(oxygine::Vector2(100, 100), 0x1F1FFF50, make_pair(position.first + 100 * j, position.second + 100 * i));
                else
                    if(matrix->get_value(make_pair(i,j)) == 3)
                        child = new Game_view(oxygine::Vector2(100, 100), 0xFF1F1F50, make_pair(position.first + 100 * j, position.second + 100 * i));
                    else
                        if(matrix->get_value(make_pair(i,j)) == 2)
                            child = new Game_view(oxygine::Vector2(100, 100), 0x5FFF5F50, make_pair(position.first + 100 * j, position.second + 100 * i));
                        else
                            if(matrix->get_value(make_pair(i,j)) == 8)
                            {
                                child = new Game_view(oxygine::Vector2(100, 100), 0x1F1FFF50, make_pair(position.first + 100 * j, position.second + 100 * i));
                                spGame_view child2 = new Game_view(oxygine::Vector2(40, 40), 0xFFFFFF50, make_pair(position.first + 100 * j + 30, position.second + 100 * i + 30));
                                child2->attachTo(child);
                            }
            child->attachTo(view);
            }
    }
}
//Game_view(oxygine::Vector2 new_size, int new_color, pair<int, int> new_position)
