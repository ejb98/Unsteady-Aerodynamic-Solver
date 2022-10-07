#include "Panel.h"
#include "calculateNormalVector.h"
#include "calculateArea.h"
#include <iostream>

Panel::Panel() = default;
Panel::Panel(const std::array<Point, 4>& vertices) :
	m_vertices{ vertices }
{
	m_normalVector = calculateNormalVector(m_vertices);
	m_area = calculateArea(m_vertices);
}

const std::array<Point, 4>& Panel::getVertices() const { return m_vertices; }
void Panel::setVertices(const std::array<Point, 4>& vertices)
{
	m_vertices = vertices;
	m_normalVector = calculateNormalVector(m_vertices);
	m_area = calculateArea(m_vertices);
}

const Vector& Panel::getNormalVector() const { return m_normalVector; }

double Panel::getPressure() const { return m_pressure; }
void Panel::setPressure(double pressure) { m_pressure = pressure; }

void Panel::print() const
{
	std::cout << "Normal Vector: ";
	m_normalVector.print();

	std::cout << "Surface Area: " << m_area << " m^2\n";
	std::cout << "Pressure: " << m_pressure << " Pa\n";

	std::cout << '\n';

	int index{};
	for (const auto& vertex : m_vertices)
	{
		std::cout << "Vertex " << index++ << ":\n";
		vertex.print();
	}
}