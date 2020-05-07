#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include "oxygine-framework.h"

DECLARE_SMART(Game_view, spGame_view)


using namespace std;
class Game_view : public oxygine::Actor
{
    public:
        Game_view(oxygine::Vector2 size, size_t players_cnt);

};

#endif // GAME_VIEW_H
