#ifndef WAKE_H
#define WAKE_H

#include "Mesh.h"
#include "Ring.h"
#include <vector>
#include <string>

class Wake
{
private:
	Mesh m_mesh{};

	std::vector<Ring> m_rings{};

public:
	Wake();
	Wake(const Mesh& mesh);

	const Mesh& getMesh() const;
	void setMesh(const Mesh& mesh);

	const std::vector<Ring>& getRings() const;
	void setRings(const std::vector<Ring>& rings);

	void print() const;

	void saveRings(const std::string& fileName) const;
};

#endif
