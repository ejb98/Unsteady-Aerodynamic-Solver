#ifndef CONSTRUCTRINGS_H
#define CONSTRUCTRINGS_H

#include "Ring.h"
#include "Panel.h"
#include "Mesh.h"
#include <vector>

// Construct rings directly using a mesh
std::vector<Ring> constructRings(const Mesh& mesh);

// Construct rings automatically using existing panels
std::vector<Ring> constructRings(const std::vector<Panel>& panels);

#endif