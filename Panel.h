#ifndef PANEL_H
#define PANEL_H

#include "Point.h"
#include "Vector.h"
#include <array>

class Panel
{
private:
	std::array<Point, 4> m_vertices{};

	Vector m_normalVector{};

	double m_pressure{};

	bool m_trailingEdge{};
	bool m_leadingEdge{};
	bool m_root{};

public:
	Panel();
	Panel(const std::array<Point, 4>& vertices);

	const std::array<Point, 4>& getVertices() const;
	void setVertices(const std::array<Point, 4>& vertices);

	const Vector& getNormalVector() const;

	double getPressure() const;
	void setPressure(double pressure);

	bool isOnTrailingEdge() const;
	bool isOnLeadingEdge() const;
	bool isOnRoot() const;
};

#endif