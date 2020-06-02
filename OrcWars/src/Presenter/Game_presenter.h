//Game_presenter.h for Graphics

#ifndef GAME_PRESENTER_H
#define GAME_PRESENTER_H

#include "oxygine-framework.h"
#include "../Model/Matrix.h"
#include "../View/Game_view.h"
#include "../AI/AI.h"
//#include "../Events/Events.h"

using namespace std;
namespace GameGraphics
{
    DECLARE_SMART(Game_presenter, spGame_presenter)
    class Game_presenter : public oxygine::EventDispatcher
    {
        private:
            spGame_view view;
            spColorRectSprite background;
            GameModel::spMatrix field;
            oxygine::Point size;
            size_t x;
            size_t y;
            pair<int, int> position;
            GameModel::Graph* graph;
            int size_shift;
            bool game_over_flag;
            bool init_flag;
        public:
            Game_presenter(oxygine::Point new_size, size_t players_cnt, pair<int, int> new_position);
            void create_background();
            void set_field(size_t x1, size_t y1);
            void create_field();
            void init_view();
            void update(oxygine::spActor actor);
            void count_update();
            void show(oxygine::spActor actor);
            void hide();
            bool get_game_over_flag();
    };
}
#endif // GAME_PRESENTER_H
