#include "Matrix.h"
#include <iostream>

void printMatrix(const Matrix& matrix)
{
	for (const auto& row : matrix)
	{
		for (const auto columnValue : row)
		{
			std::cout << columnValue << ' ';
		}

		std::cout << '\n';
	}
}