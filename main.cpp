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
#include "difference.h"
#include "zeros.h"
#include "dot.h"
#include "shedWake.h"
#include "solve.h" // See note*
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

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
	
	// File path for output CSV files
	std::string filePath{ "C:\\Users\\ethan\\Projects\\cpp\\csv-files\\" };

	// Rectangular wing dimensions
	double chord{ 1.0 };
	double span{ 6.0 };

	// Number of panels
	int chordwisePanels{ 4 };
	int spanwisePanels{ 12 };

	// Time parameters
	double startTime{ 0.0 };
	double endTime{ 1.875 };
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
	double deltaTime{ time[1] - time[0] };

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

	calculateVelocities(history, deltaTime);

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
			std::vector<Velocity> vWakeOnWing(vNormalSurfaceMotion.size());
			std::vector<double> vNormalWakeOnWing(vNormalSurfaceMotion.size());

			int index{};
			for (const auto& boundVortexRing : history[step].surface.getRings())
			{

				for (const auto& wakeVortexRing : history[step - 1].wake.getRings())
				{
					InducedVelocity inducedVelocity{ wakeVortexRing.induceVelocityOn(boundVortexRing.getCollocationPoint(),
						wakeVortexRing.getVorticityStrength()) };

					vWakeOnWing[index].x += inducedVelocity.totalVelocity.x;
					vWakeOnWing[index].y += inducedVelocity.totalVelocity.y;
					vWakeOnWing[index].z += inducedVelocity.totalVelocity.z;
				}

				vNormalWakeOnWing[index] += dot(vWakeOnWing[index], boundVortexRing.getNormalVector());

				++index;
			}

			gammaSurface = solve(aSurfaceSurface, difference(vNormalSurfaceMotion, vNormalWakeOnWing));
		}

		// Assign vorticity strengths to each bound vortex ring
		std::vector<Ring> boundRings{ history[step].surface.getRings() };

		for (int index{ 0 }; index < gammaSurface.size(); ++index)
		{
			boundRings[index].setVorticityStrength(gammaSurface[index]);
		}

		history[step].surface.setRings(boundRings);

		// Wake Shedding and Rollup
		if (step >= 1)
		{
			// Wake Shedding
			shedWake(history, step);

			// Wake Rollup
			Mesh wakeMesh{ history[step].wake.getMesh() };

			Matrix xMatrix{ wakeMesh.xMatrix };
			Matrix yMatrix{ wakeMesh.yMatrix };
			Matrix zMatrix{ wakeMesh.zMatrix };

			int rows{ static_cast<int>(xMatrix.size()) };
			int columns{ static_cast<int>(xMatrix[0].size())};

			Matrix xVelocity{ zeros(rows, columns) };
			Matrix yVelocity{ zeros(rows, columns) };
			Matrix zVelocity{ zeros(rows, columns) };

			for (int row{ 0 }; row < rows; ++row)
			{
				for (int column{ 1 }; column < columns; ++column)
				{
					Position position{ xMatrix[row][column], yMatrix[row][column], zMatrix[row][column] };
					Point point{ position };

					for (const auto& boundVortexRing : history[step].surface.getRings())
					{
						InducedVelocity inducedVelocity{ boundVortexRing.induceVelocityOn(point, boundVortexRing.getVorticityStrength()) };

						xVelocity[row][column] += inducedVelocity.totalVelocity.x;
						yVelocity[row][column] += inducedVelocity.totalVelocity.y;
						zVelocity[row][column] += inducedVelocity.totalVelocity.z;
					}

					for (const auto& wakeVortexRing : history[step].wake.getRings())
					{
						InducedVelocity inducedVelocity{ wakeVortexRing.induceVelocityOn(point, wakeVortexRing.getVorticityStrength()) };

						xVelocity[row][column] += inducedVelocity.totalVelocity.x;
						yVelocity[row][column] += inducedVelocity.totalVelocity.y;
						zVelocity[row][column] += inducedVelocity.totalVelocity.z;
					}

				}
			}

			for (int row{ 0 }; row < rows; ++row)
			{
				for (int column{ 1 }; column < columns; ++column)
				{
					xMatrix[row][column] += xVelocity[row][column] * deltaTime;
					yMatrix[row][column] += yVelocity[row][column] * deltaTime;
					zMatrix[row][column] += zVelocity[row][column] * deltaTime;
				}
			}

			Mesh newWakeMesh{ xMatrix, yMatrix, zMatrix };

			Wake newWake{ newWakeMesh };

			std::vector<Ring> newRings{ newWake.getRings() };

			int index{};
			for (auto& ring : newRings)
			{
				ring.setVorticityStrength(history[step].wake.getRings()[index].getVorticityStrength());
				++index;
			}

			newWake.setRings(newRings);

			history[step].wake = newWake;
		}

		// File output
		std::string stepString{ std::to_string(step) };
		std::string panelFileName{ "Panels_" + stepString + ".csv" };
		std::string boundRingFileName{ "Bound_Rings_" + stepString + ".csv" };
		std::string wakeRingFileName{ "Wake_Rings_" + stepString + ".csv" };

		if (step == 74)
		{
			history[step].surface.getPanelMesh().writeToFiles(filePath, panelFileName);
			history[step].surface.getRingMesh().writeToFiles(filePath, boundRingFileName);
			history[step].wake.getMesh().writeToFiles(filePath, wakeRingFileName);
		}
	}

	// ****** MAIN TIME LOOP END ******

	return 0;
}