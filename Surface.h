#ifndef SURFACE_H
#define SURFACE_H

#include "Mesh.h"
#include "Panel.h"
#include "Ring.h"
#include <vector>

class Surface
{
private:
	Mesh m_panelMesh{};
	Mesh m_ringMesh{};

	std::vector<Panel> m_panels{};
	std::vector<Ring> m_rings{};

public:
	Surface();
	Surface(const Mesh& panelMesh);

	const Mesh& getPanelMesh() const;
	void setPanelMesh(const Mesh& panelMesh);

	const Mesh& getRingMesh() const;

	const std::vector<Ring>& getRings() const;
	void setRings(const std::vector<Ring>& rings);

	void translate(double xOffset, double yOffset, double zOffset);

	void rotate(double roll, double pitch, double yaw);

	void print() const;
};

#endif