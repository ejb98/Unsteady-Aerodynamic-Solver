#include "Vector.h"
#include "Velocity.h"

double dot(const Vector& vectorA, const Vector& vectorB)
{
	return vectorA.x * vectorB.x + vectorA.y * vectorB.y + vectorA.z * vectorB.z;
}

double dot(const Velocity& velocity, const Vector& vector)
{
	return velocity.x * vector.x + velocity.y * vector.y + velocity.z * vector.z;
}