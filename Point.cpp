#include "Point.h"
#include <iostream>

void Point::print() const
{
	position.print();
	velocity.print();
}