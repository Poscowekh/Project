//Game_view.cpp for Graphics

#include "Game_view.h"

namespace GameGraphics
{
    Game_view::Game_view(Vector2 new_size, pair<int, int> new_position, GameModel::spMatrix mtrx)
    {
        size = new_size;
        position = new_position;
        matrix = mtrx;
        //scale_factor_x = matrix->get_columns() / size.x;
        //scale_factor_y = matrix->get_rows() / size.y;
        rect_size = Vector2(size.x / matrix->get_columns(), size.y / matrix->get_rows());
        static_flag = false;
        start_flag = true;
        last_color = 1;
        colors.push_back(Color(0x0D6E91FF));
        colors.push_back(Color(0xD46F3DFF));
        colors.push_back(Color(0xB9BF0BFF));
        colors.push_back(Color(0xA336D6FF));
        colors.push_back(Color(0x5C361FFF));
    }

    void Game_view::draw_field()
    {
        field = new Sprite();
        field->setSize(size.x, size.y);
        field->setPosition(position.first, position.second);
        //actor->addChild(field);
    }

    void Game_view::draw_grass(int x, int y)
    {
        ResAnim* res_grass = ViewHelper::res.getResAnim(("grass"));
        spSprite grass = new Sprite();
        grass->setResAnim(res_grass);
        grass->setSize(rect_size.x, rect_size.y);
        grass->setPosition(rect_size.x * x, rect_size.y * y);
        grass->attachTo(field);
    }

    void Game_view::draw_block(int x, int y)        //add type later
    {
        spSprite block = new Sprite();
        //spSprite block_1 = new Sprite();
        ResAnim* res_block;
        /*if(x == 0)
            res_block = ViewHelper::res.getResAnim("mountains_left");
        if(x == matrix->get_columns() - 1)
            res_block = ViewHelper::res.getResAnim("mountains_right");
        if(y == 0)
            res_block = ViewHelper::res.getResAnim("mountains_up");
        if(y == matrix->get_rows() - 1)
            res_block = ViewHelper::res.getResAnim("mountains_down");
        if(x == 0 && y == matrix->get_rows() - 1)

        if(0 < y && y < matrix->get_rows() - 1 && 0 < x && x < matrix->get_columns() - 1)*/
        res_block = ViewHelper::res.getResAnim("mountains");
        block->setPosition(rect_size.x * x, rect_size.y * y);
        block->setResAnim(res_block);
        block->setSize(rect_size.x, rect_size.y);
        block->attachTo(field);
    }

    void Game_view::update(oxygine::spActor actor)
    {
        if(static_flag)
            reset();
        else
        {
            draw_field();
            static_flag = true;
        };
        for(size_t i = 0; i < matrix->get_rows(); i++)
            for(size_t j = 0; j < matrix->get_columns(); j++)
            {
                draw_grass(j, i);;
                if(matrix->get_value(make_pair(i,j)) == 3)
                    draw_block(j,i);
            }
        draw_snakes();
        for(size_t i = 0; i < matrix->get_rows(); i++)
            for(size_t j = 0; j < matrix->get_columns(); j++)
                if(matrix->get_value(make_pair(i,j)) == 2)
                    draw_food(j,i);
        if(!static_flag)
            for(size_t i = 0; i < food_sprites.size(); i++)
                addChild(food_sprites[i]);
        start_flag = true;
        show(actor);
    }

    void Game_view::show(oxygine::spActor actor)
    {
        actor->addChild(field);
    }

    void Game_view::draw_food(int x, int y)
    {
        spSprite food = new Sprite();
        ResAnim* res_food;
        /*int r = rand() % 3;
        if(r == 0)*/
            res_food = ViewHelper::res.getResAnim("green_apple");
        /*if(r == 1)
            res_food = ViewHelper::res.getResAnim("red_apple");
        if(r == 2)
            res_food = ViewHelper::res.getResAnim("yellow_apple");*/
        float tmp_x = rect_size.x * x + rect_size.x / 4;
        float tmp_y = rect_size.y * y + rect_size.y / 4;
        food->setPosition(tmp_x, tmp_y);
        food->setResAnim(res_food);
        food->setSize(rect_size.x / 2, rect_size.y / 2);
        field->addChild(food);
        //food_sprites.push_back(food);
    }

    void Game_view::draw_snakes()
    {
        snakes = matrix->get_snakes();
        vector< vector<spSprite> > tmp_snakes;
        tmp_snakes.resize(snakes.size());
        for(size_t i = 0; i < snakes.size(); i++)
            if(snakes[i].get_size() > 0)
            {
                vector<spSprite> tmp;
                tmp.resize(snakes[i].get_size());
                for(size_t j = 0; j < snakes[i].get_size(); j++)
                {
                    spSprite sprite = new Sprite();
                    float pos_x = rect_size.x * snakes[i].part_of_body(j).second + rect_size.x / 2;
                    float pos_y = rect_size.y * snakes[i].part_of_body(j).first + rect_size.y / 2;
                    sprite->setAnchor(Vector2(0.5, 0.5));
                    sprite->setPosition(pos_x, pos_y);
                    if(i == 0)
                        sprite->setColor(colors[0]);
                    else
                        sprite->setColor(colors[last_color]);
                    if(j == 0 && matrix->get_value(snakes[i].get_head()) == 8)
                    {
                        sprite->setResAnim(ViewHelper::res.getResAnim("head"));
                        sprite->setSize(rect_size.x * 4 / 3, rect_size.y * 4 / 3);
                        spSprite sprite_eyes = new Sprite();
                        sprite_eyes->setResAnim(ViewHelper::res.getResAnim("eyes"));
                        sprite_eyes->attachTo(sprite);
                        sprite_eyes->setSize(sprite->getSize().x, sprite->getSize().y);
                        sprite_eyes->setPosition(0, -rect_size.y / 17 * 3);
                        sprite->setRotationDegrees(get_head_rotation(i));
                    }
                    else
                        if(j < snakes[i].get_size() - 1)
                        {
                            sprite->setResAnim(ViewHelper::res.getResAnim("body"));
                            sprite->setSize(rect_size.x, rect_size.y);
                            sprite->setRotationDegrees(get_body_rotation(i,j));
                        }
                        else
                        {
                            sprite->setResAnim(ViewHelper::res.getResAnim("tail"));
                            sprite->setSize(rect_size.x, rect_size.y);
                            sprite->setRotationDegrees(get_body_rotation(i,j));
                        }
                    tmp[j] = sprite;
                    field->addChild(sprite);
                }
            }
        snake_sprites = tmp_snakes;
    }

    int Game_view::get_head_rotation(int i)
    {
        float rotation;
        pair<int, int> movement_vector = snakes[i].get_movement_vector();
        if(movement_vector.first != 0)
        {
            if(movement_vector.first > 0)
                rotation = 180;
            else
                rotation = 0;
        }
        else
        {
            if(movement_vector.second > 0)
                rotation = 90;
            else
                rotation = -90;
        }
        return rotation;
    }

    int Game_view::get_body_rotation(int i, int j)
    {
        float rotation;
        if(j > 0)
        {
            int tmp_x = snakes[i].part_of_body(j - 1).second - snakes[i].part_of_body(j).second;
            int tmp_y = snakes[i].part_of_body(j - 1).first - snakes[i].part_of_body(j).first;
            pair<int, int> tmp_vector = make_pair(tmp_x, tmp_y);
            if(tmp_vector.first != 0)
            {
              if(tmp_vector.first > 0)
                  rotation = 90;
              else
                  rotation = -90;
            }
            else
            {
              if(tmp_vector.second > 0)
                  rotation = 180;
              else
                  rotation = 0;
            }
        }
        else
            rotation = get_head_rotation(i);
        return rotation;
    }

    void Game_view::reset()
    {
        field->removeChildren();
        /*
        for(size_t i = 0; i < snake_sprites.size(); i++)
            for(size_t j = 0; j < snake_sprites[i].size(); j++)
                actor->removeChild(snake_sprites[i][j]);
        for(size_t j = 0; j < food_sprites.size(); j++)
            actor->removeChild(food_sprites[j]);*/
        //addChild(field);
        //food_sprites.clear();
    }

    bool Game_view::get_game_over_flag()
    {
        return game_over_flag;
    }

    void Game_view::hide_all()
    {
        reset();
        removeChild(field);
    }
}
