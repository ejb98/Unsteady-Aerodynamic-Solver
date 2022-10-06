#include <vector>
#include <cassert>

std::vector<double> linspace(double start, double end, int numberOfSteps)
{
	assert(numberOfSteps >= 2 && "linspace failed, numberOfSteps must be 2 or greater");

	std::vector<double> output(numberOfSteps);

	double increment{ (end - start) / (numberOfSteps - 1) };

	for (int step{ 0 }; step < numberOfSteps; ++step)
	{
		output[step] = step * increment;
	}

	return output;
}