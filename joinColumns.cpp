#include "Matrix.h"
#include "zeros.h"
#include <vector>
#include <cassert>

Matrix joinColumns(const std::vector<double>& columnA, const std::vector<double>& columnB)
{
	assert(columnA.size() == columnB.size() && "joinColumns failed, columns must be the same height");

	int numberOfRows{ static_cast<int>(columnA.size()) };
	int numberOfColumns{ 2 };

	Matrix matrix{ zeros(numberOfRows, numberOfColumns) };

	for (int row{ 0 }; row < numberOfRows; ++row)
	{
		matrix[row][0] = columnA[row];
		matrix[row][1] = columnB[row];
	}

	return matrix;
}