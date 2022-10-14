#ifndef CALCULATETANGENTVECTOR_H
#define CALCULATETANGENTVECTOR_H

#include "Point.h"
#include "Vector.h"
#include <array>

Vector calculateTangentVector(const std::array<Point, 4>& vertices);

#endif