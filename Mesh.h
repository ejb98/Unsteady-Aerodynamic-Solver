#ifndef MESH_H
#define MESH_H

#include <vector>

using matrix_t = std::vector<std::vector<double>>;

struct Mesh
{
	matrix_t xMatrix{};
	matrix_t yMatrix{};
	matrix_t zMatrix{};
};

#endif
