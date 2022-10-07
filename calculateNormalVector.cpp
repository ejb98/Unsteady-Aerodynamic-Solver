#include "Point.h"
#include "Vector.h"
#include "calculateVector.h"
#include "cross.h"
#include "dot.h"
#include <cmath>
#include <array>

Vector calculateNormalVector(const std::array<Point, 4>& vertices)
{
	Vector vectorA{ calculateVector(vertices[0], vertices[2]) };
	Vector vectorB{ calculateVector(vertices[3], vertices[1]) };
	Vector crossProduct{ cross(vectorA, vectorB) };

	double divisor{ std::sqrt(dot(crossProduct, crossProduct)) };

	Vector normalVector{};

	normalVector.x = crossProduct.x / divisor;
	normalVector.y = crossProduct.y / divisor;
	normalVector.z = crossProduct.z / divisor;

	return normalVector;
}