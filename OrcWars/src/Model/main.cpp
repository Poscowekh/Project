// main.cpp

#include "Matrix.h"
#include "Snake.h"

using namespace std;

int main() {
	int x;
	int y;
	cin >> x >> y;
	Matrix field(x, y);
    field.print();
    system("pause");
    return 0;
}
