#include "System.h"
#include <cmath>
#include <iostream>
#include <iomanip>

int main()
{
	System system{};

	const double pi{ 4.0 * std::atan(1.0) };

	std::cout << std::setprecision(15) << std::fixed << pi << '\n';

	return 0;
}