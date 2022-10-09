#include "Component.h"
#include "lastColumn.h"
#include "insertColumn.h"
#include "joinColumns.h"
#include <vector>
#include <cassert>

// Note: This function will directly modify the component at the current step of the history passed in
void shedWake(std::vector<Component>& history, int step)
{
	assert(step >= 1 && "shedWake failed, step passed in must be greater than or equal to 1");

	// Get the trailing vortex segment from this time step
	std::vector<double> currentTrailingSegmentX{ lastColumn(history[step].surface.getRingMesh().xMatrix) };
	std::vector<double> currentTrailingSegmentY{ lastColumn(history[step].surface.getRingMesh().yMatrix) };
	std::vector<double> currentTrailingSegmentZ{ lastColumn(history[step].surface.getRingMesh().zMatrix) };

	if (step == 1)
	{
		// Get the trailing vortex segment from the last time step
		std::vector<double> previousTrailingSegmentX{ lastColumn(history[step - 1].surface.getRingMesh().xMatrix) };
		std::vector<double> previousTrailingSegmentY{ lastColumn(history[step - 1].surface.getRingMesh().yMatrix) };
		std::vector<double> previousTrailingSegmentZ{ lastColumn(history[step - 1].surface.getRingMesh().zMatrix) };

		// Concatenate the trailing segment from this time step with the previous one to make the first wake vortex rings
		Matrix xMatrix{ joinColumns(currentTrailingSegmentX, previousTrailingSegmentX) };
		Matrix yMatrix{ joinColumns(currentTrailingSegmentY, previousTrailingSegmentY) };
		Matrix zMatrix{ joinColumns(currentTrailingSegmentZ, previousTrailingSegmentZ) };

		Mesh wakeMesh{ xMatrix, yMatrix, zMatrix };

		Wake wake{ wakeMesh };

		// Assign the vorticity of the trailing bound vortex rings of the last step to the all of the wake
		// vortex rings of this time step.
		std::vector<Ring> wakeRings{ wake.getRings() };

		int numberOfWakeRings{ static_cast<int>(wakeRings.size()) };
		int numberOfBoundRings{ static_cast<int>(history[step - 1].surface.getRings().size()) };
		int indexOfLastBoundRing{ numberOfBoundRings - 1 };
		int indexOfFirstBoundRingOnTrailingEdge{ indexOfLastBoundRing - numberOfWakeRings + 1 };

		int count{};
		for (int index{ indexOfFirstBoundRingOnTrailingEdge }; index < numberOfBoundRings; ++index)
		{
			wakeRings[count].setVorticityStrength(history[step - 1].surface.getRings()[index].getVorticityStrength());
			++count;
		}

		wake.setRings(wakeRings);

		history[step].wake = wake;
	}
	else
	{
		// Get the wake mesh from the last time step
		Mesh previousWakeMesh{ history[step - 1].wake.getMesh() };

		Matrix xMatrix{ previousWakeMesh.xMatrix };
		Matrix yMatrix{ previousWakeMesh.yMatrix };
		Matrix zMatrix{ previousWakeMesh.zMatrix };

		// Insert the trailing segment of this time step into the beginning of the wake from the last time step
		insertColumn(currentTrailingSegmentX, xMatrix);
		insertColumn(currentTrailingSegmentY, yMatrix);
		insertColumn(currentTrailingSegmentZ, zMatrix);

		Mesh wakeMesh{ xMatrix, yMatrix, zMatrix };

		Wake wake{ wakeMesh };

		// Assign the vorticity of the trailing bound vortex rings of the last step to the all of the wake
		// vortex rings of this time step.
		std::vector<Ring> wakeRings{ wake.getRings() };

		int numberOfSpanwiseWakeRings{ static_cast<int>(wake.getMesh().xMatrix.size()) - 1 };
		int numberOfBoundRings{ static_cast<int>(history[step - 1].surface.getRings().size()) };
		int indexOfLastBoundRing{ numberOfBoundRings - 1 };
		int indexOfFirstBoundRingOnTrailingEdge{ indexOfLastBoundRing - numberOfSpanwiseWakeRings + 1 };

		int count{};
		for (int index{ indexOfFirstBoundRingOnTrailingEdge }; index < numberOfBoundRings; ++index)
		{
			wakeRings[count].setVorticityStrength(history[step - 1].surface.getRings()[index].getVorticityStrength());
			++count;
		}

		// Assign the vorticity of the wake at the last time step to all of the remaining wake rings of this
		// time step

		for (const auto& previousWakeVortexRing : history[step - 1].wake.getRings())
		{
			wakeRings[count].setVorticityStrength(previousWakeVortexRing.getVorticityStrength());
			++count;
		}

		wake.setRings(wakeRings);

		history[step].wake = wake;
	}
}