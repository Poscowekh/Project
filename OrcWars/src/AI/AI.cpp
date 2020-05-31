#include "AI.h"

using namespace std;
namespace GameModel
{
    AI::AI(spMatrix mtrx)
    {
        matrix = mtrx;
        for(size_t i = 0; i < matrix->get_snakes().size(); i++)
        {
            size_t tmp = matrix->get_snakes()[i].get_id();
            ids.push_back(tmp);
            if(ids[i] != 100)
                ai_id = ids[i];
        }
        ai_graph = new Graph(ai_id, matrix);
        human_graph = new Graph(100, matrix);
        //compete_flag = false;
    };

    void AI::count_ways()
    {
        ai_graph->Dijkstra();
        ai_way = ai_graph->get_way();
        //ai_graph->print_distance();
        human_graph->Dijkstra();
        human_way = human_graph->get_way();
    };

    void AI::choose_way()
    {
        if(human_way.size() >= ai_way.size() && ai_way.size() > 0 && matrix->get_snakes()[matrix->return_snakes_index_by_id(ai_id)].get_death_flag() != true)
        {
            pair<int, int> next = ai_graph->get_coords(ai_way.back());
            pair<int, int> head = matrix->get_snake_head(ai_id);
            pair<int, int> move = make_pair(next.first - head.first, next.second - head.second);
            matrix->change_movement(ai_id, move);
        }
        else
            matrix->change_movement(ai_id, choose_safe());
    };

    pair<int,int> AI::choose_safe()
    {
        pair<size_t,size_t> next;
        pair<int,int> move;
        vector<size_t> new_way = ai_graph->safe_way(human_graph->get_distance());
        if(new_way.size() != 0 && new_way.front() /*!= ai_graph->get_snake_head()*/)
        {
            next = ai_graph->get_coords(new_way.back());
            int move_x = next.first - ai_graph->get_snake_head().first;
            int move_y = next.second - ai_graph->get_snake_head().second;
            move = make_pair(move_x, move_y);
        }
        else
            move = rand_move();
        return move;
    };

    pair<int, int> AI::rand_move()
    {
        pair<int,int> move;
        int rand_num = rand() % 4;
        switch(rand_num)
        {
        case 0:
            move = make_pair(0,1);
            break;
        case 1:
            move = make_pair(0,-1);
            break;
        case 2:
            move = make_pair(1,0);
            break;
        case 3:
            move = make_pair(-1,0);
            break;
        }
        return move;
    }

    void AI::print_ways()
    {
        for(size_t i = 0; i < ai_way.size(); i++)
            cout << ai_way[i] << ' ';
        cout << endl;
        for(size_t i = 0; i < human_way.size(); i++)
            cout << human_way[i] << ' ';
        cout << endl;
    }

    /*void AI::update_way()
    {

    }*/
}
