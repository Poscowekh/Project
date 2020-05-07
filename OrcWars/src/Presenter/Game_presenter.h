#ifndef GAME_PRESENTER_H
#define GAME_PRESENTER_H

#include "oxygine-framework.h"
#include "../Model/Matrix.h"
#include "../View/Game_view.h"

DECLARE_SMART(Game_presenter, spGame_presenter)

using namespace std;
class Game_presenter : public oxygine::EventDispatcher
{
    spGame_view view;
    GameModel::spMatrix matrix;
    public:
        void show();
        void hide();
        Game_presenter();
};

#endif // GAME_PRESENTER_H
