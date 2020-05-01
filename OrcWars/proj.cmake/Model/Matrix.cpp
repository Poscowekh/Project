// matrix.cpp

#include "Matrix.h"

using namespace std;

Matrix::Matrix() {//Creates default matrix 
    rows = 10;
    columns = 10;
    matrix.resize(columns);
    for (int i = 0; i < columns; i++) {
        matrix[i].resize(rows, 0);
    }
};

Matrix::Matrix(int x, int y) {//Creates matrix
    rows = y;
    columns = x;
    matrix.resize(columns);
    for (int i = 0; i < columns; i++)
    {
        matrix[i].resize(rows, 0);
    }
};

int& Matrix::operator()(const int &row, const int &column) {//Returns value
    return this->matrix[row][column];
};

int Matrix::getRows() const {
    return this->rows;
};

int Matrix::getCols() const {
    return this->columns;
};

void Matrix::print() const {			//Prints matrix
    cout << "Matrix: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j=0; j<columns; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
	}
}
