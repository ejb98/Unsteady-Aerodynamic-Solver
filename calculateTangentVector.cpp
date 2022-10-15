#include "Point.h"
#include "Vector.h"
#include "calculateNormalVector.h"
#include "calculateVector.h"
#include "calculateCollocationPoint.h"
#include "cross.h"
#include "dot.h"
#include <array>
#include <cmath>

Vector calculateTangentVector(const std::array<Point, 4>& vertices)
{
	Vector vector{ calculateVector(vertices[2], vertices[1]) };

	double divisor{ std::sqrt(dot(vector, vector)) };

	Vector tangentVector{ vector.x / divisor, vector.y / divisor, vector.z / divisor };

	return tangentVector;
}