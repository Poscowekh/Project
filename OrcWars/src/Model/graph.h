// graph.cpp for Model

#ifndef GRAPH_H
#define GRAPH_H
#include <stdlib.h>
#include <vector>
#include "node.h"
using namespace std;
namespace GameModel
{
    class Graph
    {
        private:
            size_t height;
            size_t width;
            vector<Node> nodes;
            vector<pair<int, int> > nearest_food;
            pair<int, int> snakes_head;
        public:
            Graph(pair<int, int> left_top_corner, pair<int, int> rigth_bottom_corner);
            size_t get_height();
            size_t get_width();
            size_t get_count();

    };
}
#endif // GRAPH_H
