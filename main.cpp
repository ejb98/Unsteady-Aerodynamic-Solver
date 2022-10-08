#include "Mesh.h"
#include "Matrix.h"
#include "Surface.h"
#include "Wake.h"
#include "Component.h"
#include "constructRectangularMesh.h"
#include "calculateVelocities.h"
#include "influenceCoefficients.h"
#include "normalVelocityDueToMotion.h"
#include "printMatrix.h"
#include "printVector.h"
#include "linspace.h"
#include "solve.h" // See note*
#include <iostream>
#include <vector>
#include <cmath>

// *If compiling with Visual Studio, you will need to add /bigobj as an
// additional option in the Properties > Configuration Properties >
// C/C++ > Command Line > Additional Options box. You will also need to
// download and extract the Eigen C++ linear algebra library, then go to
// Properties > Configuration Properties > C/C++ > General > Additional
// Include Directories and add the folder that you extracted. These steps
// are needed because the solve.cpp function uses the Eigen library. If you
// are compiling from the command line, modify "#include <Eigen/Dense> in
// solve.cpp to "#include "eigen-#.#.#/Eigen/Dense" if you have placed the
// extracted eigen folder in the same directory as the .cpp and .h files

int main()
{
	// ***** INPUT SECTION START *****
	
	// Rectangular wing dimensions
	double chord{ 1.0 };
	double span{ 6.0 };

	// Number of panels
	int chordwisePanels{ 4 };
	int spanwisePanels{ 12 };

	// Time parameters
	double startTime{ 0.0 };
	double endTime{ 2.0 };
	int timeSteps{ 75 };

	// Static parameters
	double angleOfAttack{ 3.1415926535 * 5.0 / 180.0 };

	// Kinematic parameters
	double xVelocity{ -5.0 };
	double rollAmplitude{ 3.1415926535 * 45.0 / 180.0 };
	double rollFrequency{ 2.0 * 3.1415926535 * (1.0 / (endTime - startTime)) };

	// ****** INPUT SECTION END ******

	// Construct mesh from inputs and create surface from mesh
	Mesh mesh{ constructRectangularMesh(chord, span, chordwisePanels, spanwisePanels) };
	Surface baseSurface{ mesh };

	// Apply angle of attack
	baseSurface.rotate(0.0, angleOfAttack, 0.0);

	// Create time vector
	std::vector<double> time{ linspace(startTime, endTime, timeSteps) };

	// Create history of component
	std::vector<Component> history(time.size());

	for (int step{ 0 }; step < history.size(); ++step)
	{
		Surface surface{ baseSurface };

		surface.rotate(rollAmplitude * std::sin(rollFrequency * time[step]), 0.0, 0.0);
		surface.translate(xVelocity * time[step], 0.0, 0.0);
		
		Component component{ surface };

		history[step] = component;
	}

	calculateVelocities(history, time[1] - time[0]);

	// ***** MAIN TIME LOOP START *****

	for (int step{ 0 }; step < history.size(); ++step)
	{
		std::cout << "Step " << step << "...\n";

		// Solution for vorticity strengths of the bound vortex rings
		std::vector<double> vNormalSurfaceMotion{ normalVelocityDueToMotion(history[step]) };
		Matrix aSurfaceSurface{ influenceCoefficients(history[step]) };
		std::vector<double> gammaSurface(vNormalSurfaceMotion.size());

		if (step == 1)
		{
			gammaSurface = solve(aSurfaceSurface, vNormalSurfaceMotion);
		}
		else if (step != 0)
		{
			// Need to swap this out with the correct equation
			gammaSurface = solve(aSurfaceSurface, vNormalSurfaceMotion);
		}

		// Wake Shedding
	}

	// ****** MAIN TIME LOOP END ******

	return 0;
}