// Snake.h for Snake

#ifndef SNAKE_H
#define SNAKE_H

using namespace std;

#include <stdlib.h>
#include <vector>
#include <utility>
#include <string>

class Snake {
	private:
		vector< pair<int, int> > body;
	public:
		Snake();
		Snake(int, int, int);
        void snake_move(int) const;
	    int get_size();
};
#endif // SNAKE_H
