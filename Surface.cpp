#include "Surface.h"
#include "Mesh.h"
#include "constructPanels.h"
#include "constructRings.h"
#include "translateMesh.h"
#include "rotateMesh.h"
#include "printMatrix.h"
#include <vector>
#include <array>
#include <iostream>

Surface::Surface() = default;

Surface::Surface(const Mesh& mesh) :
	m_mesh{ mesh }
{
	m_panels = constructPanels(m_mesh);
	m_rings = constructRings(m_panels);
}

const Mesh& Surface::getMesh() const { return m_mesh; }

void Surface::setMesh(const Mesh& mesh)
{
	m_mesh = mesh;
	m_panels = constructPanels(m_mesh);
	m_rings = constructRings(m_panels);
}

const std::vector<Ring>& Surface::getRings() const { return m_rings; }
void Surface::setRings(const std::vector<Ring>& rings) { m_rings = rings; }

void Surface::translate(double xOffset, double yOffset, double zOffset)
{
	setMesh(translateMesh(m_mesh, xOffset, yOffset, zOffset));
}

void Surface::rotate(double roll, double pitch, double yaw)
{
	setMesh(rotateMesh(m_mesh, roll, pitch, yaw));
}

void Surface::print() const
{
	int panelIndex{};
	for (const auto& panel : m_panels)
	{
		std::cout << "Panel " << panelIndex++ << ":\n";
		panel.print();
		std::cout << '\n';
	}

	int ringIndex{};
	for (const auto& ring : m_rings)
	{
		std::cout << "Ring " << ringIndex++ << ":\n";
		ring.print();
		std::cout << '\n';
	}
}