#include "Panel.h"
#include "Matrix.h"
#include "Position.h"
#include "Point.h"
#include <vector>
#include <cassert>

std::vector<Panel> constructPanels(const Matrix& xMatrix, const Matrix& yMatrix, const Matrix& zMatrix)
{
	std::vector<Panel> panels{};

	int rows{ static_cast<int>(xMatrix.size()) };
	int columns{ static_cast<int>(xMatrix[0].size())};

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

			Panel panel{ vertices };

			if (column == 0)
				panel.setLeadingEdgeStatus(true);

			if (column == columns - 2)
				panel.setTrailingEdgeStatus(true);

			if (row == 0)
				panel.setRootStatus(true);

			if (row == rows - 2)
				panel.setTipStatus(true);

			panels.push_back(panel);
		}
	}
	return panels;
}