#ifndef POINT_H
#define POINT_H

#include "Position.h"
#include "Velocity.h"

struct Point
{
	Position position{};
	Velocity velocity{};

	void print() const;
};

#endif