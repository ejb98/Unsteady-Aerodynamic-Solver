#ifndef RING_H
#define RING_H

#include "Point.h"
#include "Vector.h"
#include "InducedVelocity.h"
#include <array>

class Ring
{
private:
	std::array<Point, 4> m_vertices{};

	Point m_collocationPoint{};

	Vector m_normalVector{};

	double m_vorticityStrength{};

public:
	Ring();
	Ring(const std::array<Point, 4>& vertices);

	const std::array<Point, 4>& getVertices() const;
	void setVertices(const std::array<Point, 4>& vertices);

	const Point& getCollocationPoint() const;
	void setCollocationPoint(const Point& collocationPoint);

	const Vector& getNormalVector() const;

	double getVorticityStrength() const;
	void setVorticityStrength(double vorticityStrength);

	InducedVelocity induceVelocityOn(const Point& point, double vorticityStrength = 1.0) const;

	void print() const;
};

#endif
