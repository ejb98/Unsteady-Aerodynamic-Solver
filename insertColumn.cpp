#include "Matrix.h"
#include "zeros.h"
#include <vector>
#include <cassert>

// Note: This function directly manipulates the matrix passed in by inserting a column at the beginning
void insertColumn(const std::vector<double>& firstColumn, Matrix& matrix)
{
	assert(firstColumn.size() == matrix.size() && "insertColumn failed, column and matrix must be the same height");

	int numberOfRows{ static_cast<int>(matrix.size()) };
	int numberOfOldColumns{ static_cast<int>(matrix[0].size())};
	int numberOfNewColumns{ numberOfOldColumns + 1 };

	Matrix newMatrix{ zeros(numberOfRows, numberOfNewColumns) };

	for (int row{ 0 }; row < numberOfRows; ++row)
	{
		for (int column{ 0 }; column < numberOfNewColumns; ++column)
		{
			if (column == 0)
			{
				newMatrix[row][column] = firstColumn[row];
			}
			else
			{
				newMatrix[row][column] = matrix[row][column - 1];
			}
		}
	}

	matrix = newMatrix;
}