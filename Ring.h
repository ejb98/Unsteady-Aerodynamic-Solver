#ifndef RING_H
#define RING_H

#include "Point.h"
#include "Vector.h"
#include <array>

class Ring
{
private:
	std::array<Point, 4> m_vertices{};

	Point m_collocationPoint{};

	Vector m_normalVector{};

	double m_vorticityStrength{};

	bool m_trailingEdge{};
	bool m_leadingEdge{};
	bool m_root{};
	bool m_tip{};

public:
	Ring();
	Ring(const std::array<Point, 4>& vertices);

	const std::array<Point, 4>& getVertices() const;
	void setVertices(const std::array<Point, 4>& vertices);

	const Point& getCollocationPoint() const;
	const Vector& getNormalVector() const;

	double getVorticityStrength() const;
	void setVorticityStrength(double vorticityStrength);

	bool isOnTrailingEdge() const;
	bool isOnLeadingEdge() const;
	bool isOnTip() const;
	bool isOnRoot() const;
};

#endif
