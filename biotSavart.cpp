#include "Velocity.h"
#include "Vector.h"
#include "Point.h"
#include "calculateVector.h"
#include "cross.h"
#include "dot.h"
#include <cmath>

Velocity biotSavart(const Point& point, const Point& point1, const Point& point2, double vorticityStrength)
{
	constexpr double pi{ 3.1415926535 };
	constexpr double cutoffRadius{ 1.0e-10 };

	Vector r0{ calculateVector(point1, point2) };
	Vector r1{ calculateVector(point1, point) };
	Vector r2{ calculateVector(point2, point) };
	Vector r1CrossR2{ cross(r1, r2) };

	double r1CrossR2Squared{ dot(r1CrossR2, r1CrossR2) };
	double r1Magnitude{ std::sqrt(dot(r1, r1)) };
	double r2Magnitude{ std::sqrt(dot(r2, r2)) };

	Velocity velocity{};

	if (r1Magnitude < cutoffRadius || r2Magnitude < cutoffRadius || r1CrossR2Squared < cutoffRadius)
	{
		return velocity;
	}

	double r0DotR1{ dot(r0, r1) };
	double r0DotR2{ dot(r0, r2) };

	double coefficient{ (vorticityStrength / (4.0 * pi * r1CrossR2Squared)) *
						((r0DotR1 / r1Magnitude) - (r0DotR2 / r2Magnitude)) };

	velocity.x = r1CrossR2.x * coefficient;
	velocity.y = r1CrossR2.y * coefficient;
	velocity.z = r1CrossR2.z * coefficient;

	return velocity;
}