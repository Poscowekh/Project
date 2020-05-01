// matrix.h

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Matrix
{
	private:
		unsigned rows;
		unsigned columns;
	public:
		vector< vector<unsigned> > matrix;
		Matrix();
		Matrix(unsigned, unsigned);
		unsigned& operator()(const unsigned &, const unsigned &);
		unsigned getRows() const;
	    unsigned getCols() const;
	    void print() const;
};
#endif // MATRIX_H
