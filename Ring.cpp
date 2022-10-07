#include "Ring.h"
#include "calculateCollocationPoint.h"
#include "calculateNormalVector.h"
#include <iostream>

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

void Ring::print() const
{
	int index{};
	for (const auto& vertex : m_vertices)
	{
		std::cout << "Vertex " << index++ << ": ("
			<< vertex.position.x << ", "
			<< vertex.position.y << ", "
			<< vertex.position.z << ")\n";
	}
}