#include "Game_view.h"

Game_view::Game_view()
{
    oxygine::spColorRectSprite sprite = new oxygine::spColorRectSprite();
    sprite->setColor(oxygine::Color(0xFF0000FF));
    sprite->setSize(oxygine::Vector2(100, 100));
    addChild(sprite);
}
