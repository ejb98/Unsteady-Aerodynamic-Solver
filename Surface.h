#ifndef SURFACE_H
#define SURFACE_H

#include "Mesh.h"
#include "Panel.h"
#include "Ring.h"
#include <vector>

class Surface
{
private:
	Mesh m_mesh{};

	std::vector<Panel> m_panels{};
	std::vector<Ring> m_rings{};

public:
	Surface();
	Surface(const Mesh& mesh);

	const Mesh& getMesh() const;
	void setMesh(const Mesh& mesh);
};

#endif