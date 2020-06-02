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
            bool start_flag;
            bool game_over_flag;
            spSprite field;
            vector<spSprite> food_sprites;
            vector< vector<spSprite> > snake_sprites;
            vector<int> destroy_ids;
            vector<GameModel::Snake> snakes;
            Resources res;
            float scale_factor_x;
            float scale_factor_y;
            size_t last_color;
            vector<Color> colors;
        public:
            Game_view(Vector2 new_size, pair<int, int> new_position, GameModel::spMatrix mtrx);
            int get_body_rotation(int i, int j);
            int get_head_rotation(int i);
            bool get_game_over_flag();
            void draw_field();
            void show(oxygine::spActor actor);
            void draw_grass(int x, int y);
            void draw_block(int x, int y);
            void draw_food(int x, int y);
            void draw_snakes();
            void reset();
            void update(oxygine::spActor actor);
            void hide_all();
    };
}
#endif // GAME_VIEW_H
