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
        //field->setColor(Color(0x00000000));
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
        reset();
        if(!static_flag)
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
            if(snakes[i].get_size() > 1)
                for(size_t j = 1; j < snakes[i].get_size(); j++)
                {
                    spSprite tmp_sprite = new Sprite();
                    float tmp_pos_x = position.first + rect_size.x * snakes[i].part_of_body(j).second;
                    float tmp_pos_y = position.second + rect_size.y * snakes[i].part_of_body(j).first;
                    tmp_sprite->setPosition(tmp_pos_x, tmp_pos_y);
                    if(j < snakes[i].get_size() - 1)
                    {
                        ResAnim* res_body = ViewHelper::res.getResAnim("body");
                        tmp_sprite->setResAnim(res_body);
                    }
                    else
                    {
                        ResAnim* res_tail = ViewHelper::res.getResAnim("tail");
                        tmp_sprite->setResAnim(res_tail);
                    }
                    //if(init_rotation_flag)
                        //tmp_sprite->setRotationDegrees(get_snake_init_rotation(snakes[i].get_movement_vector()));
                    //else
                        //tmp_sprite->setRotationDegrees(get_snake_rotation(i,j));
                    tmp_sprite->setSize(rect_size.x, rect_size.y);
                    tmp[j] = tmp_sprite;
                    addChild(tmp_sprite);
                }
            ResAnim* res_head = ViewHelper::res.getResAnim("head");
            spSprite head = new Sprite();
            float tmp_pos_x = position.first + rect_size.x * snakes[i].get_head().second;
            float tmp_pos_y = position.second + rect_size.y * snakes[i].get_head().first;
            head->setPosition(tmp_pos_x, tmp_pos_y);
            //float anchor_x = head->getPosition().x + rect_size.x / 2;
            //float anchor_y = head->getPosition().y + rect_size.y / 2;
            //head->setAnchor(Vector2(anchor_x, anchor_y));
            head->setResAnim(res_head);
            //head->setRotationDegrees(get_snake_init_rotation(snakes[i].get_movement_vector()));
            head->setSize(rect_size.x, rect_size.y);
            tmp[0] = head;
            addChild(head);
            tmp_snakes.push_back(tmp);
        }
        snake_sprites.clear();
        snake_sprites = tmp_snakes;
    }

    int Game_view::get_snake_init_rotation(pair<int, int> movement_vector)
    {
        int rotation;
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

    int Game_view::get_snake_rotation(int i, int j)
    {
        return snake_sprites[i][j - 1]->getRotation();
    }

    void Game_view::reset()
    {
        /*for(size_t i = 0; i < snake_sprites.size(); i++)
            for(size_t j = 0; j < snake_sprites[i].size(); j++)
                removeChild(snakes_sprites[i][j]);
        for(size_t j = 0; j < food_sprites.size(); j++)
            removeChild(food_sprites[i]);*/
        addChild(field);
        food_sprites.clear();
    }
}
