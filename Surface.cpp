#include "Surface.h"
#include "Mesh.h"
#include "constructPanels.h"
#include "constructRings.h"
#include "printMatrix.h"
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
void Surface::setMesh(const Mesh& mesh) { m_mesh = mesh; }

void Surface::print() const
{
	std::cout << "X Matrix:\n";
	printMatrix(m_mesh.xMatrix);
	std::cout << '\n';

	std::cout << "Y Matrix:\n";
	printMatrix(m_mesh.yMatrix);
	std::cout << '\n';

	std::cout << "Z Matrix:\n";
	printMatrix(m_mesh.zMatrix);
	std::cout << '\n';

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