//Game_view.h for Graphics

#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include "oxygine-framework.h"
#include "../Model/Matrix.h"
#include "../ViewHelper.h"
#include <random>
#include <time.h>

using namespace std;
namespace GameGraphics
{
    DECLARE_SMART(Game_view, spGame_view)
    class Game_view : public oxygine::Actor
    {
        private:
            Vector2 size;
            Vector2 rect_size;
            pair<int, int> position;
            GameModel::spMatrix matrix;
            bool static_flag;
            spSprite field;
            vector<spSprite> food_sprites;
            vector< vector<spSprite> > snake_sprites;
            vector<GameModel::Snake> snakes;
            Resources res;
            float scale_factor_x;
            float scale_factor_y;
            int delay;
        public:
            Game_view(Vector2 new_size, pair<int, int> new_position, GameModel::spMatrix mtrx);
            int get_snake_init_rotation(pair<int, int> movement_vector);
            int get_snake_rotation(spSprite prev);
            void init_draw();
            void draw_field();
            void draw_grass(int x, int y);
            void draw_block(int x, int y);
            void draw_food(int x, int y);
            void draw_snakes();
            void reset();
            void update_view();
    };
}
#endif // GAME_VIEW_H
