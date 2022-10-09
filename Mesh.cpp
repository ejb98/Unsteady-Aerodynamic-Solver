#include "Mesh.h"
#include "Matrix.h"
#include <fstream>
#include <iomanip>
#include <string>
#include <array>

void Mesh::writeToFiles(const std::string& filePath, const std::string& fileName) const
{
	std::array<std::string, 3> axes{ "x", "y", "z" };
	std::array<Matrix, 3> matrices{ xMatrix, yMatrix, zMatrix };

	int rows{ static_cast<int>(xMatrix.size()) };
	int columns{ static_cast<int>(xMatrix[0].size())};

	for (int index{ 0 }; index < 3; ++index)
	{
		std::ofstream file(filePath + axes[index] + fileName);

		for (int row{ 0 }; row < rows; ++row)
		{
			for (int column{ 0 }; column < columns; ++column)
			{
				file << matrices[index][row][column];

				if (column < columns - 1)
				{
					file << ',';
				}
			}
			file << '\n';
		}
	}
}