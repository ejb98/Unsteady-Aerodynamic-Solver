#include <iostream>
#include <vector>

void printVector(const std::vector<double>& vector)
{
	for (const auto value : vector)
	{
		std::cout << value << '\n';
	}
}