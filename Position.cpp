#include "Position.h"
#include <iostream>

void Position::print() const
{
	std::cout << "[" << x << ", " << y << ", " << z << "] m\n";
}