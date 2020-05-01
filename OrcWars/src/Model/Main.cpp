// main.cpp

#include "Matrix.h"
#include "Snake.h"

using namespace std;

int main() {
    int x = 5;
    int y = 5;
    //cin >> x >> y;
	Matrix field(x, y);
    field.print();
    Snake viper;
    for(int i = 0; i < (int)viper.body.size(); i++) {
        field.matrix[viper.body[i].first][viper.body[i].second] = 1;
	};
    field.print();
    viper.snake_move(make_pair(1,0));
    for(int i = 0; i < (int)viper.body.size(); i++) {
        field.matrix[viper.body[i].first][viper.body[i].second] = 1;
    };
    field.print();
    cout << viper.body.size();
    //system("pause");
    return 0;
}
