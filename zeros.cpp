#include "Matrix.h"
#include <vector>
#include <cassert>

Matrix zeros(int rows, int columns)
{
	assert(rows > 0 && columns > 0 && "zeros failed, rows and columns must be greater than 0");

	Matrix matrix(rows, std::vector<double>(columns));

	return matrix;
}