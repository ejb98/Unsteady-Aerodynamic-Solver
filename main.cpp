#include "Mesh.h"
#include "Surface.h"
#include "constructRectangularMesh.h"

int main()
{
	double chord{ 1.0 };
	double span{ 6.0 };

	int chordwisePanels{ 2 };
	int spanwisePanels{ 2 };

	Mesh mesh{ constructRectangularMesh(chord, span, chordwisePanels, spanwisePanels) };

	Surface surface{ mesh };

	surface.print();

	return 0;
}