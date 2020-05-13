//Game_presenter.cpp for Graphics

#include "Game_presenter.h"
#include <iostream>

namespace GameGraphics
{
    Game_presenter::Game_presenter(Point display_size, size_t players_cnt, pair<int, int> new_position)
    {
        //int size_shift = 80;
        size = display_size;
        position = new_position;
        //float scale_factor_x = (display_size.x - 40) / display_size.x;
        //float scale_factor_y = (display_size.y - 40) / display_size.y;

        int m = 8;
        int n = 12;
        field = new GameModel::Matrix(m, n); //Matrix m rows by n columns

        field->spawn_borderline();
        field->add_snake(2, make_pair(2,4), 100);            //Snake of size 2 at (1,1)
        field->change_movement(100, make_pair(0, 1));         //Moves right 1 time
        field->spawn_block("wall", make_pair(4,4), 1);
        field->spawn_food("apple", make_pair(6,6), 2);
        field->spawn_food("apple", make_pair(5,10), 3);
        field->spawn_food("apple", make_pair(2,10), 4);
        field->spawn_food("apple", make_pair(2,1), 5);
        init_view();

        addEventListener(ox::core::EVENT_SYSTEM, [this](Event* ev){
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
        );
    }

    void Game_presenter::init_view()
    {
        int size_shift = 80;
        pair<int, int> view_pos = make_pair(size_shift / 2, size_shift / 2);
        view = new Game_view(Vector2(size.x - size_shift, size.y - size_shift), view_pos, field);
    }

    void Game_presenter::update()
    {
        field->update_matrix();
        field->print();
        view->update();
        show(getStage());
    }


    void Game_presenter::show(oxygine::spActor actor)
    {
        actor->addChild(view);
    }

    void Game_presenter::hide() {}
}
//Game_view(Vector2 new_size, int new_color, pair<int, int> new_position)
