//Game_presenter.h for Graphics


#ifndef GAME_PRESENTER_H
#define GAME_PRESENTER_H

#include "oxygine-framework.h"
#include "../Model/Matrix.h"
#include "../View/Game_view.h"

using namespace std;
namespace GameGraphics
{
    DECLARE_SMART(Game_presenter, spGame_presenter)
    class Game_presenter : public oxygine::EventDispatcher
    {
        private:
            spGame_view view;
            GameModel::spMatrix matrix;
            oxygine::Point size;
            pair<int, int> position;
        public:
            Game_presenter(oxygine::Point new_size, size_t players_cnt, pair<int, int> new_position, GameModel::spMatrix mtrx);
            void init_view();
            void update();
            void count_update();
            void show(oxygine::spActor actor);
            void hide();
    };
}
#endif // GAME_PRESENTER_H
