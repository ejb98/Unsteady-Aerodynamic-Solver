#include "zeros.h"
#include "Matrix.h"
#include <vector>
#include <tuple>

std::tuple<Matrix, Matrix> meshgrid(const std::vector<double>& xVector, const std::vector<double>& yVector)
{
	int rows{ static_cast<int>(yVector.size()) };
	int columns{ static_cast<int>(xVector.size()) };

	Matrix xMatrix{ zeros(rows, columns) };
	Matrix yMatrix{ zeros(rows, columns) };

	for (int row{ 0 }; row < rows; ++row)
	{
		for (int column{ 0 }; column < columns; ++column)
		{
			xMatrix[row][column] = xVector[column];
			yMatrix[row][column] = yVector[row];
		}
	}

	return std::make_tuple(xMatrix, yMatrix);
}
