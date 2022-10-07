#include "Surface.h"

Surface::Surface() = default;

const Mesh& Surface::getMesh() const { return m_mesh; }
void Surface::setMesh(const Mesh& mesh) { m_mesh = mesh; }