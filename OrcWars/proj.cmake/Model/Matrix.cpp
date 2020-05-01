// matrix.cpp

#include "matrix.h"

using namespace std;

Matrix::Matrix() //Creates default matrix
{ 
    rows = 10;
    columns = 10;
    matrix.resize(columns);
    for (unsigned i=0; i<columns; i++)
    {
        matrix[i].resize(rows, 0);
    }
};
Matrix::Matrix(unsigned x, unsigned y) //Creates matrix
{ 
    rows = y;
    columns = x;
    matrix.resize(columns);
    for (unsigned i=0; i<columns; i++)
    {
        matrix[i].resize(rows, 0);
    }
};
unsigned& Matrix::operator()(const unsigned &row, const unsigned &column) //Returns value
{
    return this->matrix[row][column];
};
unsigned Matrix::getRows() const  		
{
    return this->rows;
};
unsigned Matrix::getCols() const
{
    return this->columns;
};
void Matrix::print() const  			//Prints matrix
{
    cout << "Matrix: " << endl;
    for (unsigned i=0; i<rows; i++) 
	{
        for (unsigned j=0; j<columns; j++) 
		{
            cout << matrix[i][j] << " ";
        }
        cout << endl;
	}
}
