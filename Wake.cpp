#include "Wake.h"
#include "Mesh.h"
#include "constructRings.h"
#include "printMatrix.h"
#include "writeRingsToFile.h"
#include <iostream>

Wake::Wake() = default;

Wake::Wake(const Mesh& mesh) :
	m_mesh{ mesh }
{
	m_rings = constructRings(m_mesh);
}

const Mesh& Wake::getMesh() const { return m_mesh; }

void Wake::setMesh(const Mesh& mesh)
{
	m_mesh = mesh;
	m_rings = constructRings(m_mesh);
}

const std::vector<Ring>& Wake::getRings() const { return m_rings; }
void Wake::setRings(const std::vector<Ring>& rings) { m_rings = rings; }

void Wake::print() const
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

	int ringIndex{};
	for (const auto& ring : m_rings)
	{
		std::cout << "Ring " << ringIndex++ << ":\n";
		ring.print();
		std::cout << '\n';
	}
}

void Wake::saveRings(const std::string& fileName) const
{
	writeRingsToFile(m_rings, fileName);
}