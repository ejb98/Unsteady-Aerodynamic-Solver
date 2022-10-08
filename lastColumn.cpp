#include "Matrix.h"
#include <vector>

std::vector<double> lastColumn(const Matrix& matrix)
{
	int numberOfRows{ static_cast<int>(matrix.size()) };
	int numberOfColumns{ static_cast<int>(matrix[0].size()) };

	std::vector<double> columnVector(numberOfRows);

	for (int row{ 0 }; row < numberOfRows; ++row)
	{
		columnVector[row] = matrix[row][numberOfColumns - 1];
	}

	return columnVector;
}