#ifndef BIOTSAVART_H
#define BIOTSAVART_H

#include "Velocity.h"
#include "Point.h"

Velocity biotSavart(const Point& point, const Point& point1, const Point& point2, double vorticityStrength=1.0);

#endif