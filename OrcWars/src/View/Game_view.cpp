//Game_view.cpp for Graphics

#include "Game_view.h"

namespace GameGraphics
{
    Game_view::Game_view(Vector2 new_size, pair<int, int> new_position, GameModel::spMatrix mtrx)
    {
        size = new_size;
        position = new_position;
        matrix = mtrx;
        scale_factor_x = size.x / matrix->get_columns();
        scale_factor_y = size.y / matrix->get_rows();
        rect_size = Point(scale_factor_x, scale_factor_y);
        field_and_blocks_flag = false;

        res.loadXML("../../proj.cmake/Build/data/res.xml");

        draw_field();
        //draw_blocks();
    }

    void Game_view::draw_field()
    {
        spColorRectSprite field = new ColorRectSprite();
        field->setSize(size.x, size.y);
        field->setPosition(position.first, position.second);
        field->setColor(Color(0x297002FF));
        addChild(field);
    }

    void Game_view::draw_blocks()
    {
        for(size_t i = 0; i < matrix->get_rows(); i++)
            for(size_t j = 0; j < matrix->get_columns(); j++)
                draw_one_block(j,i);
    }

    void Game_view::draw_one_block(int x, int y)        //add type later
    {
        spSprite block = new Sprite();
        block->setPosition(rect_size.x * x, rect_size.y * y);
        block->setSize(rect_size);
        block->attachTo(field);
    }

    void Game_view::update_view()
    {
        if(!field_and_blocks_flag)
        {
            draw_field();
            //draw_blocks();
            field_and_blocks_flag = true;
        }
        for(size_t j = 0; j < 100; j++)
        {
            for(size_t i = 0; i < 5000; i++)
                size_t time_pass = time_pass + i;

        }
    }

    void Game_view::draw_food()
    {

    }

    void Game_view::draw_snakes()
    {

    }

    void update_snakes()
    {

    }
}
