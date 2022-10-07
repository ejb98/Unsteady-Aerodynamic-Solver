#include "Ring.h"

Ring::Ring() = default;
Ring::Ring(const std::array<Point, 4>& vertices) :
	m_vertices{ vertices } {}

const std::array<Point, 4>& Ring::getVertices() const { return m_vertices; }
void Ring::setVertices(const std::array<Point, 4>& vertices) { m_vertices = vertices; }

const Point& Ring::getCollocationPoint() const { return m_collocationPoint; }
const Vector& Ring::getNormalVector() const { return m_normalVector; }

double Ring::getVorticityStrength() const { return m_vorticityStrength; }
void Ring::setVorticityStrength(double vorticityStrength) { m_vorticityStrength = vorticityStrength; }

bool Ring::isOnTrailingEdge() const { return m_trailingEdge; }
bool Ring::isOnLeadingEdge() const { return m_leadingEdge; }
bool Ring::isOnTip() const { return m_tip; }
bool Ring::isOnRoot() const { return m_root; }