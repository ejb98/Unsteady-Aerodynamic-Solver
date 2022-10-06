#ifndef INDUCEDVELOCITY_H
#define INDUCEDVELOCITY_H

#include "Velocity.h"

struct InducedVelocity
{
	Velocity totalVelocity{};
	Velocity trailingVelocity{};
};

#endif