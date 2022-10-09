#include "Mesh.h"
#include <fstream>
#include <iomanip>

void Mesh::writeToFile(std::string& fileName) const
{
	std::ofstream file(fileName);

	int rows{ static_cast<int>(xMatrix.size()) };
	int columns{ static_cast<int>(xMatrix[0].size())};

	file << "x,y,z\n";
	for (int row{ 0 }; row < rows; ++row)
	{
		for (int column{ 0 }; column < columns; ++column)
		{
			file << std::setprecision(6) << std::fixed <<
				xMatrix[row][column] << ',' << yMatrix[row][column] << ',' << zMatrix[row][column] << '\n';
		}
	}
}