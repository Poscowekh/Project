// Snake.h for Snake

#ifndef SNAKE_H
#define SNAKE_H

using namespace std;

#include <stdlib.h>
#include <vector>
#include <utility>
#include <string>

class Snake {
	public:
		vector< pair<int, int> > body;
		Snake();
		Snake(int size, pair<int, int> head);
        void snake_move(pair<int, int> direction);
	    int get_size();
};
#endif // SNAKE_H
