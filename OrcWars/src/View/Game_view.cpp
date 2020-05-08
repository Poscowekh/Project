#include "Game_view.h"

namespace GameGraphics
{
    Game_view::Game_view(oxygine::Vector2 new_size, int new_color, pair<int, int> new_position)
    {
        size = new_size;
        color = new_color;
        position = new_position;
        oxygine::spColorRectSprite sprite = new oxygine::ColorRectSprite();
        sprite->setColor(oxygine::Color(color));
        sprite->setSize(size);
        sprite->setPosition(position.first, position.second);
        addChild(sprite);
    }
}
