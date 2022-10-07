#include "Vector.h"

double dot(const Vector& vectorA, const Vector& vectorB)
{
	return vectorA.x * vectorB.x + vectorA.y * vectorB.y + vectorA.z * vectorB.z;
}