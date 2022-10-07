#ifndef SURFACE_H
#define SURFACE_H

#include "Mesh.h"

class Surface
{
private:
	Mesh m_mesh{};

public:
	Surface();

	const Mesh& getMesh() const;
	void setMesh(const Mesh& mesh);
};

#endif