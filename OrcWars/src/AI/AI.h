#ifndef AI_H
#define AI_H

#include "../Model/Graph.h";

using namespace std;
namespace GameModel
{
    class AI
    {
        private:
            size_t ai_id;
            Graph* ai_graph;
            Graph* human_graph;
            vector<size_t> ai_way;
            vector<size_t> human_way;
            vector<size_t> ids;
            spMatrix matrix;
            bool compete_flag;
            bool game_over_flag;
        public:
            AI(spMatrix mtrx);
            void count_ways();
            void choose_way();
            pair<int,int> choose_safe();
            pair<int,int> rand_move();
            void print_ways();
    };
}
#endif // AI_H
