#include <vector>

std::vector<double> linspace(double start, double end, int numberOfSteps)
{
	std::vector<double> output(numberOfSteps);

	double increment{ (end - start) / (numberOfSteps - 1) };

	for (int step{ 0 }; step < numberOfSteps; ++step)
	{
		output[step] = step * increment;
	}

	return output;
}