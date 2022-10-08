#include "Mesh.h"

Mesh translateMesh(const Mesh& mesh, double xOffset, double yOffset, double zOffset)
{
	Mesh newMesh{ mesh };

	for (auto& row : newMesh.xMatrix)
	{
		for (auto& columnValue : row)
		{
			columnValue += xOffset;
		}
	}

	for (auto& row : newMesh.yMatrix)
	{
		for (auto& columnValue : row)
		{
			columnValue += yOffset;
		}
	}

	for (auto& row : newMesh.zMatrix)
	{
		for (auto& columnValue : row)
		{
			columnValue += zOffset;
		}
	}

	return newMesh;
}