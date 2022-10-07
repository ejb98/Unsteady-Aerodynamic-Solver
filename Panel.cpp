#include "Panel.h"

Panel::Panel() = default;
Panel::Panel(const std::array<Point, 4>& vertices) :
	m_vertices{ vertices } {}

const std::array<Point, 4>& Panel::getVertices() const { return m_vertices; }
void Panel::setVertices(const std::array<Point, 4>& vertices) { m_vertices = vertices; }

const Vector& Panel::getNormalVector() const { return m_normalVector; }

double Panel::getPressure() const { return m_pressure; }
void Panel::setPressure(double pressure) { m_pressure = pressure; }

bool Panel::isOnTrailingEdge() const { return m_trailingEdge; }
bool Panel::isOnLeadingEdge() const { return m_leadingEdge; }
bool Panel::isOnRoot() const { return m_root; }