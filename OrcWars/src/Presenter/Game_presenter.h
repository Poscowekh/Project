#ifndef GAME_PRESENTER_H
#define GAME_PRESENTER_H

#include "oxygine-framework.h"

DECLARE_SMART(Game_presenter, spGame_presenter)

class Game_presenter : public oxygine::EventDispatcher
{
    public:
        Game_presenter();
};

#endif // GAME_PRESENTER_H
