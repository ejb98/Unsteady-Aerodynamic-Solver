#include "Mesh.h"
#include "Surface.h"
#include "Wake.h"
#include "Component.h"
#include "constructRectangularMesh.h"
#include "calculateVelocities.h"
#include "linspace.h"
#include <iostream>
#include <vector>
#include <cmath>

int main()
{
	// ***** INPUT SECTION START *****
	
	// Rectangular wing dimensions
	double chord{ 1.0 };
	double span{ 6.0 };

	// Number of panels
	int chordwisePanels{ 12 };
	int spanwisePanels{ 10 };

	// Time parameters
	double startTime{ 0.0 };
	double endTime{ 2.0 };
	int timeSteps{ 50 };

	// Static parameters
	double angleOfAttack{ 3.1415926535 * 5.0 / 180.0 };

	// Kinematic parameters
	double xVelocity{ -5.0 };
	double rollAmplitude{ 3.1415926535 * 45.0 / 180.0 };
	double rollFrequency{ 2.0 * 3.1415926535 * (1.0 / (endTime - startTime)) };

	// ****** INPUT SECTION END ******

	Mesh mesh{ constructRectangularMesh(chord, span, chordwisePanels, spanwisePanels) };
	Surface surface{ mesh };

	// Apply angle of attack
	surface.rotate(0.0, angleOfAttack, 0.0);

	// Create time vector
	std::vector<double> time{ linspace(startTime, endTime, timeSteps) };

	// Create history of component
	std::vector<Component> history(time.size());

	for (int step{ 0 }; step < history.size(); ++step)
	{
		surface.rotate(rollAmplitude * std::sin(rollFrequency * time[step]), 0.0, 0.0);
		surface.translate(xVelocity * time[step], 0.0, 0.0);
		
		Component component{ surface };

		history[step] = component;
	}

	calculateVelocities(history, time);

	return 0;
}