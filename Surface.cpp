#include "Surface.h"
#include "Mesh.h"
#include "constructBoundRingMesh.h"
#include "constructPanels.h"
#include "constructRings.h"
#include "translateMesh.h"
#include "rotateMesh.h"
#include "writePanelsToFile.h"
#include "writeRingsToFile.h"
#include <vector>
#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>

Surface::Surface() = default;

Surface::Surface(const Mesh& panelMesh) :
	m_panelMesh{ panelMesh }
{
	m_ringMesh = constructBoundRingMesh(m_panelMesh);
	m_panels = constructPanels(m_panelMesh);
	m_rings = constructRings(m_ringMesh);
}

const Mesh& Surface::getPanelMesh() const { return m_panelMesh; }

void Surface::setPanelMesh(const Mesh& panelMesh)
{
	m_panelMesh = panelMesh;
	m_ringMesh = constructBoundRingMesh(m_panelMesh);
	m_panels = constructPanels(m_panelMesh);
	m_rings = constructRings(m_ringMesh);
}

const Mesh& Surface::getRingMesh() const { return m_ringMesh; }

const std::vector<Ring>& Surface::getRings() const { return m_rings; }
void Surface::setRings(const std::vector<Ring>& rings) { m_rings = rings; }

void Surface::translate(double xOffset, double yOffset, double zOffset)
{
	setPanelMesh(translateMesh(m_panelMesh, xOffset, yOffset, zOffset));
}

void Surface::rotate(double roll, double pitch, double yaw)
{
	setPanelMesh(rotateMesh(m_panelMesh, roll, pitch, yaw));
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

void Surface::savePanels(const std::string& fileName) const
{
	writePanelsToFile(m_panels, fileName);
}

void Surface::saveRings(const std::string& fileName) const
{
	writeRingsToFile(m_rings, fileName);
}