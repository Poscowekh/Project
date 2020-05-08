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
            pair<int, int> position;
        public:
            void show(oxygine::spActor actor);
            void hide();
            Game_presenter(oxygine::Vector2 size, size_t players_cnt, GameModel::spMatrix mtrx, pair<int, int> new_position);
            void draw_matrix();
    };
}
#endif // GAME_PRESENTER_H
