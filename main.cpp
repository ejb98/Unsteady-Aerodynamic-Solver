#include "Matrix.h"
#include "Mesh.h"
#include "linspace.h"
#include "zeros.h"

#include <iostream>
#include <vector>

int main()
{
	Mesh mesh{};

	std::vector<double> test{ linspace(0.0, 5.0, 5) };

	Matrix matrix{ zeros(5, 5) };

	for (int i{ 0 }; i < test.size(); ++i)
		std::cout << test[i] << '\n';

	for (int i{ 0 }; i < matrix.size(); ++i)
	{
		for (int j{ 0 }; j < matrix[0].size(); ++j)
		{
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}