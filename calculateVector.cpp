#include "Point.h"
#include "Vector.h"

Vector calculateVector(const Point& pointA, const Point& pointB)
{
	Vector vector{};

	vector.x = pointB.position.x - pointA.position.x;
	vector.y = pointB.position.y - pointA.position.y;
	vector.z = pointB.position.z - pointA.position.z;

	return vector;
}