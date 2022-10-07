#include "Wake.h"

Wake::Wake() = default;

const Mesh& Wake::getMesh() const { return m_mesh; }
void Wake::setMesh(const Mesh& mesh) { m_mesh = mesh; }