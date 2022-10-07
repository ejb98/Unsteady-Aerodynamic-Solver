#ifndef CALCULATENORMALVECTOR_H
#define CALCULATENORMALVECTOR_H

#include "Point.h"
#include "Vector.h"
#include <array>

Vector calculateNormalVector(const std::array<Point, 4>& vertices);

#endif