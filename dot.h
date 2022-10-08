#ifndef DOT_H
#define DOT_H

#include "Vector.h"
#include "Velocity.h"

double dot(const Vector& vectorA, const Vector& vectorB);

double dot(const Velocity& velocity, const Vector& vector);

#endif
