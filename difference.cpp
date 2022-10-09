#include <vector>
#include <cassert>

std::vector<double> difference(const std::vector<double>& vectorA, const std::vector<double>& vectorB)
{
	assert(vectorA.size() == vectorB.size() && "difference failed, vectors must be the same size");

	std::vector<double> newVector(vectorA.size());

	for (int index{ 0 }; index < vectorA.size(); ++index)
	{
		newVector[index] = vectorA[index] - vectorB[index];
	}

	return newVector;
}