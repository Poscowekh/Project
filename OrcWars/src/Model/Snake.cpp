// Snake.cpp for Snake

#include "Snake.h"

using namespace std;

Snake::Snake() {
    body.push_back(make_pair(0,0));
}

Snake::Snake(int size, pair<int, int> head) { //Creates Snake of size at x,y_
    body.resize(size);
    for (int i = 0; i < size; i++) {
        body[i] = make_pair(head.first + i, head.second);
    }
}

int Snake::get_size() {  
    return this->body.size();
};

 void Snake::snake_move(pair<int, int> direction){ //Moves Snake one block in direction
	for (int i = 0; i < (int)body.size(); i++){
        body[i].first = direction.first;
        body[i].second = direction.second;
    };
}
