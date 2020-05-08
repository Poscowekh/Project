#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include "oxygine-framework.h"
#include "../Model/Matrix.h"

using namespace std;
namespace GameGraphics
{
    DECLARE_SMART(Game_view, spGame_view)
    class Game_view : public oxygine::Actor
    {
        private:
            oxygine::Vector2 size;
            int color;
            pair<int, int> position;
        public:
            Game_view(oxygine::Vector2 new_size, int new_color, pair<int, int> new_position);
    };
}
#endif // GAME_VIEW_H
