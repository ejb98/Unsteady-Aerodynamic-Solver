#include "Ring.h"
#include "Panel.h"
#include "Mesh.h"
#include "Matrix.h"
#include "Position.h"
#include "Point.h"
#include <vector>
#include <array>

std::vector<Ring> constructRings(const Mesh& mesh)
{
	Matrix xMatrix{ mesh.xMatrix };
	Matrix yMatrix{ mesh.yMatrix };
	Matrix zMatrix{ mesh.zMatrix };

	std::vector<Ring> rings{};

	int rows{ static_cast<int>(xMatrix.size()) };
	int columns{ static_cast<int>(xMatrix[0].size()) };

	for (int column{ 0 }; column < columns - 1; ++column)
	{
		for (int row{ 0 }; row < rows - 1; ++row)
		{
			Position position1{ xMatrix[row][column],         yMatrix[row][column],         zMatrix[row][column] };
			Position position2{ xMatrix[row + 1][column],     yMatrix[row + 1][column],     zMatrix[row + 1][column] };
			Position position3{ xMatrix[row + 1][column + 1], yMatrix[row + 1][column + 1], zMatrix[row + 1][column + 1] };
			Position position4{ xMatrix[row][column + 1],     yMatrix[row][column + 1],     zMatrix[row][column + 1] };

			Point vertex1{ position1 };
			Point vertex2{ position2 };
			Point vertex3{ position3 };
			Point vertex4{ position4 };

			std::array<Point, 4> vertices{ vertex1, vertex2, vertex3, vertex4 };

			Ring ring{ vertices };

			rings.push_back(ring);
		}
	}

	return rings;
}