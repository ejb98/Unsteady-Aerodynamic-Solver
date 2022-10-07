#include "Ring.h"
#include "calculateCollocationPoint.h"
#include "calculateNormalVector.h"

Ring::Ring() = default;
Ring::Ring(const std::array<Point, 4>& vertices) :
	m_vertices{ vertices }
{
	m_collocationPoint = calculateCollocationPoint(m_vertices);
	m_normalVector = calculateNormalVector(m_vertices);
}

const std::array<Point, 4>& Ring::getVertices() const { return m_vertices; }
void Ring::setVertices(const std::array<Point, 4>& vertices)
{
	m_vertices = vertices;
	m_collocationPoint = calculateCollocationPoint(m_vertices);
	m_normalVector = calculateNormalVector(m_vertices);
}

const Point& Ring::getCollocationPoint() const { return m_collocationPoint; }
const Vector& Ring::getNormalVector() const { return m_normalVector; }

double Ring::getVorticityStrength() const { return m_vorticityStrength; }
void Ring::setVorticityStrength(double vorticityStrength) { m_vorticityStrength = vorticityStrength; }