#include "Panel.h"
#include "calculateNormalVector.h"

Panel::Panel() = default;
Panel::Panel(const std::array<Point, 4>& vertices) :
	m_vertices{ vertices }
{
	m_normalVector = calculateNormalVector(m_vertices);
}

const std::array<Point, 4>& Panel::getVertices() const { return m_vertices; }
void Panel::setVertices(const std::array<Point, 4>& vertices) { m_vertices = vertices; }

const Vector& Panel::getNormalVector() const { return m_normalVector; }

double Panel::getPressure() const { return m_pressure; }
void Panel::setPressure(double pressure) { m_pressure = pressure; }

void Panel::setTrailingEdgeStatus(bool status) { m_trailingEdge = status; }
void Panel::setLeadingEdgeStatus(bool status) { m_leadingEdge = status; }
void Panel::setRootStatus(bool status) { m_root = status; }
void Panel::setTipStatus(bool status) { m_tip = status; }

bool Panel::isOnTrailingEdge() const { return m_trailingEdge; }
bool Panel::isOnLeadingEdge() const { return m_leadingEdge; }
bool Panel::isOnRoot() const { return m_root; }
bool Panel::isOnTip() const { return m_tip; }