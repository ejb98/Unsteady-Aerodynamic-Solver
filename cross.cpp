#include "Vector.h"

Vector cross(const Vector& vectorA, const Vector& vectorB)
{
	Vector vector{};

	vector.x = vectorA.y * vectorB.z - vectorA.z * vectorB.y;
	vector.y = vectorA.z * vectorB.x - vectorA.x * vectorB.z;
	vector.z = vectorA.x * vectorB.y - vectorA.y * vectorB.x;

	return vector;

}