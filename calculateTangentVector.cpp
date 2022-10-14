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
	Point collocationPoint{ calculateCollocationPoint(vertices) };

	Point farEdgePoint{ collocationPoint.position.x, vertices[1].position.y, collocationPoint.position.z };

	Vector vectorA{ calculateNormalVector(vertices) };
	Vector vectorB{ calculateVector(collocationPoint, farEdgePoint) };
	Vector crossProduct{ cross(vectorA, vectorB) };

	double divisor{ std::sqrt(dot(crossProduct, crossProduct)) };

	Vector tangentVector{};

	tangentVector.x = crossProduct.x / divisor;
	tangentVector.y = crossProduct.y / divisor;
	tangentVector.z = crossProduct.z / divisor;

	return tangentVector;
}