#ifndef GAME_PRESENTER_H
#define GAME_PRESENTER_H

#include "oxygine-framework.h"

DECLARE_SMART(Game_presenter, sp_Game_presenter);

class Game_presenter
{
    public:
        class Presenter : public oxygine::EventDispatcher
        {

        };

    Game_presenter();
};

#endif // GAME_PRESENTER_H
