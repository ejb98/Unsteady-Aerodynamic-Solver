#include "Mesh.h"
#include "Surface.h"
#include "constructRectangularMesh.h"
#include <iostream>

int main()
{
	double chord{ 1.0 };
	double span{ 6.0 };

	int chordwisePanels{ 12 };
	int spanwisePanels{ 10 };

	Mesh mesh{ constructRectangularMesh(chord, span, chordwisePanels, spanwisePanels) };

	Surface surface{ mesh };

	//surface.print();

	std::cout << "Surface created with " << chordwisePanels * spanwisePanels << " Panels.\n";

	return 0;
}