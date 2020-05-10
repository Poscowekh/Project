//Game_view.h for Graphics

#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include "oxygine-framework.h"
#include "../Model/Matrix.h"
#include "../ViewHelper.h"

using namespace std;
namespace GameGraphics
{
    DECLARE_SMART(Game_view, spGame_view)
    class Game_view : public oxygine::Actor
    {
        private:
            Vector2 size;
            pair<int, int> position;
            GameModel::spMatrix matrix;
            Point rect_size;
            spSprite field;
            bool field_and_blocks_flag;
            vector<spSprite> food;
            vector<spSprite> snakes;
            Resources res;
            float scale_factor_x;
            float scale_factor_y;
        public:
            Game_view(Vector2 new_size, pair<int, int> new_position, GameModel::spMatrix mtrx);
            void draw_field();
            //void draw_field_rects(int x, int y);
            void draw_blocks();
            void draw_one_block(int x, int y);
            void draw_food();
            void draw_snakes();
            void update_view();
    };
}
#endif // GAME_VIEW_H
