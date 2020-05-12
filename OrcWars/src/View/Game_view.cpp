//Game_view.cpp for Graphics

#include "Game_view.h"

namespace GameGraphics
{
    Game_view::Game_view(Vector2 new_size, pair<int, int> new_position, GameModel::spMatrix mtrx)
    {
        size = new_size;
        position = new_position;
        matrix = mtrx;
        scale_factor_x = size.x / (matrix->get_columns() * size.x);
        scale_factor_y = size.y / (matrix->get_rows() * size.y);
        rect_size = Point(scale_factor_x * size.x, scale_factor_y * size.y);
        static_flag = false;
        init_rotation_flag = true;
        //int delay = 500;
    }

    void Game_view::draw_field()
    {
        field = new Sprite();
        field->setSize(size.x, size.y);
        field->setPosition(position.first, position.second);
        addChild(field);
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
        ResAnim* res_mount = ViewHelper::res.getResAnim("mountains");
        block->setPosition(rect_size.x * x, rect_size.y * y);
        block->setResAnim(res_mount);
        block->setSize(rect_size.x, rect_size.y);
        block->attachTo(field);
    }

    void Game_view::update()
    {
        if(static_flag)
            reset();
        else
        {
            draw_field();
            for(size_t i = 0; i < matrix->get_rows(); i++)
                for(size_t j = 0; j < matrix->get_columns(); j++)
                {
                    draw_grass(j, i);;
                    if(matrix->get_value(make_pair(i,j)) == 3)
                        draw_block(j,i);
                }
            static_flag = true;
        }
        draw_snakes();
        for(size_t i = 0; i < matrix->get_rows(); i++)
            for(size_t j = 0; j < matrix->get_columns(); j++)
                if(matrix->get_value(make_pair(i,j)) == 2)
                    draw_food(j,i);
        if(!static_flag)
            for(size_t i = 0; i < food_sprites.size(); i++)
                addChild(food_sprites[i]);
        init_rotation_flag = false;
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
        food->attachTo(field);
        food_sprites.push_back(food);
    }

    void Game_view::draw_snakes()
    {
        snakes = matrix->get_snakes();
        vector< vector<spSprite> > tmp_snakes;
        tmp_snakes.resize(snakes.size());
        for(size_t i = 0; i < snakes.size(); i++)
        {
            vector<spSprite> tmp;
            tmp.resize(snakes[i].get_size());
            for(size_t j = 0; j < snakes[i].get_size(); j++)
            {
                spSprite sprite = new Sprite();
                float pos_x = rect_size.x * snakes[i].part_of_body(j).second + rect_size.x;
                float pos_y = rect_size.y * snakes[i].part_of_body(j).first + rect_size.y;
                sprite->setAnchor(Vector2(0.5, 0.5));
                sprite->setPosition(pos_x, pos_y);
                if(j == 0)
                {
                    sprite->setResAnim(ViewHelper::res.getResAnim("head"));
                    sprite->setSize(rect_size.x, rect_size.y);
                }
                else
                    if(j < snakes[i].get_size() - 1)
                    {
                        sprite->setResAnim(ViewHelper::res.getResAnim("body"));
                        sprite->setSize(rect_size.x / 3 * 2, rect_size.y / 3 * 2);
                    }
                    else
                    {
                        sprite->setResAnim(ViewHelper::res.getResAnim("tail"));
                        sprite->setSize(rect_size.x, rect_size.y);
                    }
                sprite->setRotationDegrees(get_snake_rotation(i,j));
                tmp[j] = sprite;
                addChild(sprite);
            }
        }
        snake_sprites = tmp_snakes;
    }

    int Game_view::get_snake_rotation(int i, int j)
    {
        int rotation;
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

    void Game_view::reset()
    {
        for(size_t i = 0; i < snake_sprites.size(); i++)
            for(size_t j = 0; j < snake_sprites[i].size(); j++)
                field->removeChild(snake_sprites[i][j]);
        for(size_t j = 0; j < food_sprites.size(); j++)
            field->removeChild(food_sprites[j]);
        addChild(field);
        //food_sprites.clear();
    }
}
