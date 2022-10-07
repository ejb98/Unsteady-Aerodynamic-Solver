#include "Velocity.h"
#include <iostream>

void Velocity::print() const
{
	std::cout << "[" << x << ", " << y << ", " << z << "] m/s\n";
}