#ifndef MESH_H
#define MESH_H

#include "Matrix.h"
#include <string>

struct Mesh
{
	Matrix xMatrix{};
	Matrix yMatrix{};
	Matrix zMatrix{};

	void writeToFile(std::string& fileName);
};

#endif
