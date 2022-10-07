#ifndef WAKE_H
#define WAKE_H

#include "Mesh.h"

class Wake
{
private:
	Mesh m_mesh{};

public:
	Wake();

	const Mesh& getMesh() const;
	void setMesh(const Mesh& mesh);
};

#endif
