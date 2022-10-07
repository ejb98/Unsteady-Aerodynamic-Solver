#ifndef COMPONENT_H
#define COMPONENT_H

#include "Surface.h"
#include "Wake.h"

struct Component
{
	Surface surface{};
	Wake wake{};
};

#endif
