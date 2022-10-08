#include "Ring.h"
#include "Velocity.h"
#include "InducedVelocity.h"
#include "calculateCollocationPoint.h"
#include "calculateNormalVector.h"
#include "biotSavart.h"
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
void Ring::setCollocationPoint(const Point& collocationPoint) { m_collocationPoint = collocationPoint; }

const Vector& Ring::getNormalVector() const { return m_normalVector; }

double Ring::getVorticityStrength() const { return m_vorticityStrength; }
void Ring::setVorticityStrength(double vorticityStrength) { m_vorticityStrength = vorticityStrength; }

InducedVelocity Ring::induceVelocityOn(const Point& point, double vorticityStrength) const
{
	Velocity velocity1{ biotSavart(point, m_vertices[0], m_vertices[1], vorticityStrength) };
	Velocity velocity2{ biotSavart(point, m_vertices[1], m_vertices[2], vorticityStrength) };
	Velocity velocity3{ biotSavart(point, m_vertices[2], m_vertices[3], vorticityStrength) };
	Velocity velocity4{ biotSavart(point, m_vertices[3], m_vertices[0], vorticityStrength) };

	Velocity totalVelocity{ velocity1.x + velocity2.x + velocity3.x + velocity4.x,
							velocity1.y + velocity2.y + velocity3.y + velocity4.y,
							velocity1.z + velocity2.z + velocity3.z + velocity4.z };

	Velocity trailingVelocity{ velocity2.x + velocity4.x,
							   velocity2.y + velocity4.y,
							   velocity2.z + velocity4.z };

	InducedVelocity inducedVelocity{ totalVelocity, trailingVelocity };

	return inducedVelocity;
}

void Ring::print() const
{
	std::cout << "Normal Vector: ";
	m_normalVector.print();

	std::cout << "Vorticity Strength: " << m_vorticityStrength << "\n";

	std::cout << '\n';

	int index{};
	for (const auto& vertex : m_vertices)
	{
		std::cout << "Vertex " << index++ << ":\n";
		vertex.print();
	}

	std::cout << "Collocation Point:\n";
	m_collocationPoint.print();
}