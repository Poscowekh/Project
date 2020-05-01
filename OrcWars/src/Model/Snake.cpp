// Snake.cpp for Snake

#include "Snake.h"

using namespace std;

Snake::Snake() {
    body.resize(1);
    body.push_back(make_pair(0,0));
}

/*Snake::Snake(size, x, y) { //Creates Snake of size at x,y_
    body.resize(size);
    for (int i = 0; i < size; i++) {
        body[i] = make_pair(head.first + i, head.second);
    }
}*/

int Snake::get_size() {  
    return this->body.size();
};

 void Snake::snake_move(a){ //Moves Snake one block in direction
	if (direction = "right") {
		for (int i = 0, i < body.size(), i++){
			body.swap(body[i + 1], body[i]);
			body.popback;
			body.pushback(make_pair(body[i].first + 1, body[i].second + 1))
		}
	}
}
