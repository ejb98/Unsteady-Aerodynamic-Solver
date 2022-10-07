#include "meshgrid.h"
#include "zeros.h"
#include "linspace.h"
#include "Matrix.h"
#include "Mesh.h"
#include <vector>

Mesh constructRectangularMesh(double chord, double span,
	int chordwisePanels, int spanwisePanels)
{
	std::vector<double> xVector{ linspace(0.0, chord, chordwisePanels + 1) };
	std::vector<double> yVector{ linspace(0.0, span, spanwisePanels + 1) };

	Matrix xMatrix{};
	Matrix yMatrix{};

	std::tie(xMatrix, yMatrix) = meshgrid(xVector, yVector);

	int rows{ static_cast<int>(xMatrix.size()) };
	int columns{ static_cast<int>(xMatrix[0].size()) };

	Matrix zMatrix{ zeros(rows, columns) }; // Flat mesh (no airfoil)

	Mesh mesh{ xMatrix, yMatrix, zMatrix };

	return mesh;
}