#ifndef MESH_H
#define MESH_H

#include "Matrix.h"
#include <string>

struct Mesh
{
	Matrix xMatrix{};
	Matrix yMatrix{};
	Matrix zMatrix{};

	void writeToFiles(const std::string& filePath, const std::string& fileName) const;
};

#endif
