// Matrix.h for Model

#ifndef SNAKE_GAME_MATRIX_H
#define SNAKE_GAME_MATRIX_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include "oxygine-framework.h"
#include "Snake.h"
#include "Food.h"
#include "Block.h"

using namespace std;
namespace GameModel
{
    DECLARE_SMART(Matrix, spMatrix)
    class Matrix : public oxygine::EventDispatcher
    {
        private:
            size_t rows;
            size_t columns;
            size_t last_seed;
            vector< vector<int> > matrix;   //The field
            vector<Snake> snakes;           //All snakes
            vector<Food> food;              //All food
            vector<Block> blocks;           //All blocks
            vector<size_t> ids_to_destroy;
            size_t new_id_snake;            //Provide a new id for each object
            size_t new_id_food;
            size_t new_id_block;
            size_t non_block_cells;
            bool start_movement_flag;
            bool player_death_flag;
        public:
            Matrix();
            Matrix(size_t m, size_t n);
            Matrix(size_t map_choise);
            size_t get_rows();
            size_t get_columns();
            size_t get_value(pair<int, int> coordinates);
            bool check_cell(pair<int, int>);
            pair<int, int> get_random_coordinates(size_t seed);
            pair<int, int> get_random_free_coordinates(size_t seed);
            void spawn_borderline();
            size_t get_new_id_snake();
            size_t get_new_id_food();
            size_t get_new_id_block();

            //for snakes
            void move_snakes();
            void change_movement(size_t id, pair<int, int> movement);
            void add_snake(size_t new_size, pair<int, int> head, size_t new_id);
            void remove_snake(size_t id);
            bool destruction_check(Snake snake);
            bool growth_check(Snake snake);
            bool destruction_by_snake_check(Snake snake);
            bool get_player_death_flag();
            pair<int, int> get_snake_head(size_t id);
            size_t get_snake_id(Snake snake);
            size_t return_snakes_index_by_id(size_t id);
            vector<Snake> get_snakes();
            vector<size_t> get_ids_to_destroy();

            //for food and blocks
            void spawn_food(string new_type, pair<int, int> new_coordinates, size_t new_id);
            void spawn_block(string new_type, pair<int, int> new_coordinates, size_t new_id);
            void remove_food(pair<int, int> coordinates);
            void remove_block(size_t remove_id);
            void check_add_food();
            int check_around(int x, int y);
            void random_borders();
            size_t get_food_id(pair<int, int> coordinates);
            size_t get_block_id(pair<int, int> coordinates);
            vector<Food> get_food();
            vector<Block> get_blocks();
            size_t get_food_count();
            size_t get_blocks_count();

            //for printing matrix
            void reset_matrix();
            void update_matrix();
            void print();
    };
}
#endif // MATRIX_H
