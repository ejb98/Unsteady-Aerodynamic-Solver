#include "Mesh.h"
#include "Matrix.h"
#include "Position.h"
#include <array>

Mesh constructBoundRingMesh(const Mesh& panelMesh)
{
	Matrix xMatrix{ panelMesh.xMatrix };
	Matrix yMatrix{ panelMesh.yMatrix };
	Matrix zMatrix{ panelMesh.zMatrix };

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

			double xDifferenceNear{ position4.x - position1.x };
			double xDifferenceFar{ position3.x - position2.x };

			double zDifferenceNear{ position4.z - position1.z };
			double zDifferenceFar{ position3.z - position2.z };

			std::array<Position, 4> newPositions{ position1, position2, position3, position4 };

			int count{};
			for (auto& position : newPositions)
			{
				double x{ position.x };
				double y{ position.y };
				double z{ position.z };

				if (count == 0 || count == 3)
				{
					x += xDifferenceNear / 4.0;
					z += zDifferenceNear / 4.0;
				}
				else
				{
					x += xDifferenceFar / 4.0;
					z += zDifferenceFar / 4.0;
				}

				position.x = x;
				position.y = y;
				position.z = z;

				++count;
			}

			xMatrix[row][column] = newPositions[0].x;
			yMatrix[row][column] = newPositions[0].y;
			zMatrix[row][column] = newPositions[0].z;

			xMatrix[row + 1][column] = newPositions[1].x;
			yMatrix[row + 1][column] = newPositions[1].y;
			zMatrix[row + 1][column] = newPositions[1].z;

			xMatrix[row + 1][column + 1] = newPositions[2].x;
			yMatrix[row + 1][column + 1] = newPositions[2].y;
			zMatrix[row + 1][column + 1] = newPositions[2].z;

			xMatrix[row][column + 1] = newPositions[3].x;
			yMatrix[row][column + 1] = newPositions[3].y;
			zMatrix[row][column + 1] = newPositions[3].z;
		}
	}
	
	Mesh ringMesh{ xMatrix, yMatrix, zMatrix };

	return ringMesh;
}