#include "Matrix.h"
#include "Vector.h"
#include "InducedVelocity.h"
#include "Component.h"
#include "zeros.h"
#include "dot.h"
#include <vector>
#include <omp.h>

Matrix influenceCoefficients(const Component& component)
{
	int numberOfRings{ static_cast<int>(component.surface.getRings().size()) };

    Matrix aMatrix{};

    for (const auto& boundVortexRing : component.surface.getRings())
    {
        Point collocationPoint{ boundVortexRing.getCollocationPoint() };

        Vector normalVector{ boundVortexRing.getNormalVector() };

        std::vector<double> matrixRow{};

        for (const auto& innerBoundVortexRing : component.surface.getRings())
        {
            InducedVelocity inducedVelocity{ innerBoundVortexRing.induceVelocityOn(collocationPoint) };

            double normalVelocity{ dot(inducedVelocity.totalVelocity, normalVector) };

            matrixRow.push_back(normalVelocity);
        }

        aMatrix.push_back(matrixRow);
    }

    return aMatrix;
}