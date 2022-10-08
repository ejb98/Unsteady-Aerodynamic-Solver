#include "Component.h"
#include <vector>

std::vector<double> normalVelocityDueToMotion(const Component& component)
{
	int numberOfRings{ static_cast<int>(component.surface.getRings().size()) };
	std::vector<double> normalVelocityVector(numberOfRings);

	for (int index{ 0 }; index < numberOfRings; ++index)
	{
		normalVelocityVector[index] = component.surface.getRings()[index].getCollocationPoint().normalVelocity;
	}

	return normalVelocityVector;
}
