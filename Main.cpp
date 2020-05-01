// main.cpp

#include "Matrix.h" 
#include "Matrix.cpp"

using namespace std;

int main() 
{
	int x = 10;
	int y = 10;
	Matrix field(x, y);
    field.print();
    system("pause");
    return 0;
}
