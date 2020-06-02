//Game_presenter.cpp for Graphics

#include "Game_presenter.h"
#include <iostream>

namespace GameGraphics
{
    Game_presenter::Game_presenter(Point display_size, size_t players_cnt, pair<int, int> new_position)
    {
        size_shift = 40;
        size = display_size;
        position = new_position;
        game_over_flag = false;
        init_flag = false;
        x = 16;
        y = 9;

        //int m = 8;                           //Size of game field
        //int n = 12;
        //field = new GameModel::Matrix(m, n); //Matrix m rows by n columns

        //create_background();

        /*field->spawn_borderline();
        field->add_snake(1, make_pair(m - 2, n - 2), 100);
        field->add_snake(1, make_pair(1,1), 102);            //Snake of size 2 at (1,1)
        field->change_movement(102, make_pair(0, 1));         //Moves right 1 time
        field->change_movement(100, make_pair(0, -1));         //Moves right 1 time
        field->spawn_block("wall", make_pair(4,4), 1);
        field->spawn_block("wall", make_pair(4,5), 1);
        field->spawn_block("wall", make_pair(4,6), 1);*/
    }

    void Game_presenter::init_view()
    {
        pair<int, int> view_pos = make_pair(size_shift, size_shift);
        view = new Game_view(Vector2(size.x - size_shift * 2, size.y - size_shift * 2), view_pos, field);
        getStage()->addEventListener(KeyEvent::KEY_DOWN, [this](Event* ev){
            if(!game_over_flag)
            {
                KeyEvent* event = (KeyEvent*) ev;
                switch(event->data->keysym.scancode)
                {
                    case SDL_SCANCODE_UP:
                        field->change_movement(100, make_pair(-1,0));
                    break;
                    case SDL_SCANCODE_W:
                        field->change_movement(100, make_pair(-1,0));
                    break;

                    case SDL_SCANCODE_RIGHT:
                        field->change_movement(100, make_pair(0,1));
                    break;
                    case SDL_SCANCODE_D:
                        field->change_movement(100, make_pair(0,1));
                    break;

                    case SDL_SCANCODE_DOWN:
                        field->change_movement(100, make_pair(1,0));
                    break;
                    case SDL_SCANCODE_S:
                        field->change_movement(100, make_pair(1,0));
                    break;

                    case SDL_SCANCODE_LEFT:
                        field->change_movement(100, make_pair(0,-1));
                    break;
                    case SDL_SCANCODE_A:
                        field->change_movement(100, make_pair(0,-1));
                    break;
                }
            }
        }
        );
    }

    void Game_presenter::update(oxygine::spActor actor)
    {
        if(!init_flag)
        {
            create_field();
            init_view();
            init_flag = true;
        }
        view->removeChildren();
        field->update_matrix();
        //field->print();
        game_over_flag = field->get_player_death_flag();
        //if(field->get_snakes().size() > 1 && !game_over_flag)
        if(!game_over_flag)
        {
            if(field->get_snakes()[1].get_death_flag() != true)
            {
                GameModel::AI* ai = new GameModel::AI(field);
                ai->count_ways();
                ai->choose_way();
            };
            view->update(actor);
        }
        else
            view->hide_all();

    }

    void Game_presenter::set_field(size_t y1, size_t x1)
    {
        x = x1;
        y = y1;
    }

    void Game_presenter::create_field()
    {
        field = new GameModel::Matrix(x, y);
    }

    void Game_presenter::show(oxygine::spActor actor)
    {
        actor->addChild(view);
    }

    void Game_presenter::create_background()
    {
        background = new ColorRectSprite();
        background->setSize(size.x - 2 * size_shift + 8, size.y - 2 * size_shift + 8);
        background->setPosition(size_shift - 4, size_shift - 4);
        background->setColor(Color(0x3B2505FF));
    }

    void Game_presenter::hide()
    {
        view->hide_all();
    }

    bool Game_presenter::get_game_over_flag()
    {
        return game_over_flag;
    }
}
