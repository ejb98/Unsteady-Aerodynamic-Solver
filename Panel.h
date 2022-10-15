#ifndef PANEL_H
#define PANEL_H

#include "Point.h"
#include "Vector.h"
#include <array>

class Panel
{
private:
	std::array<Point, 4> m_vertices{};

	Point m_collocationPoint{};

	Vector m_normalVector{};
	Vector m_tangentVector{};

	double m_area{};
	double m_pressure{};

public:
	Panel();
	Panel(const std::array<Point, 4>& vertices);

	const std::array<Point, 4>& getVertices() const;
	void setVertices(const std::array<Point, 4>& vertices);

	const Point& getCollocationPoint() const;

	const Vector& getNormalVector() const;
	const Vector& getTangentVector() const;

	double getPressure() const;
	void setPressure(double pressure);

	double getArea() const;

	void print() const;
};

#endif