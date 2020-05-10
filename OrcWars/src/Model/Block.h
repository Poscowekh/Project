// Block.h for Model

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
            size_t id;                      //Random or not number
            pair<int, int> coordinates;
            string type;                    //Wall, Mountain, Hill, Lake?
            //size_t durability             //Probable
        public:
            Block(size_t new_id, pair<int, int> new_coordinates, string new_type);
            string get_type();
            size_t get_id();
            pair<int, int> get_coordinates();
            //size_t get_durability();
    };
}
#endif // BLOCK_H
