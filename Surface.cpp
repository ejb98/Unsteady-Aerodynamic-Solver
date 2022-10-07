#include "Surface.h"
#include "Mesh.h"
#include "constructPanels.h"
#include "constructRings.h"

Surface::Surface() = default;
Surface::Surface(const Mesh& mesh) :
	m_mesh{ mesh }
{
	m_panels = constructPanels(m_mesh);
	m_rings = constructRings(m_panels);
}

const Mesh& Surface::getMesh() const { return m_mesh; }
void Surface::setMesh(const Mesh& mesh) { m_mesh = mesh; }