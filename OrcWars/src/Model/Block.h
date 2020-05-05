// Block.h for Block

#ifndef BLOCK_H
#define BLOCK_H
#include <stdlib.h>
#include <utility>
#include <string>
using namespace std;
namespace GameModel
{
    class Block
    {
        private:
            size_t id;
            pair<int, int> coordinates;
            string type;
            //size_t durability             //To make blocks destroyable(hits or something) IDK yet probably no need in it
        public:
            Block(size_t new_id, pair<int, int> new_coordinates, string new_type);
            string get_type();
            size_t get_id();
            pair<int, int> get_coordinates();
    };
}
#endif // BLOCK_H
//Might need to create complete walls
