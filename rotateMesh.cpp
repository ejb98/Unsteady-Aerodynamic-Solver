#include "Mesh.h"
#include "Matrix.h"
#include "calculateRotationMatrix.h"
#include <array>

Mesh rotateMesh(const Mesh& mesh, double roll, double pitch, double yaw)
{
    Matrix rotationMatrix{ calculateRotationMatrix(roll, pitch, yaw) };

    Mesh newMesh{ mesh };

    int rows{ static_cast<int>(newMesh.xMatrix.size()) };
    int columns{ static_cast<int>(newMesh.xMatrix[0].size())};

    for (int row{ 0 }; row < rows; ++row)
    {
        for (int column{ 0 }; column < columns; ++column)
        {
            double xValue{ newMesh.xMatrix[row][column] };
            double yValue{ newMesh.yMatrix[row][column] };
            double zValue{ newMesh.zMatrix[row][column] };

            std::array<double, 3> newValues{};

            int count{};
            for (const auto& row : rotationMatrix)
            {
                newValues[count] = row[0] * xValue + row[1] * yValue + row[2] * zValue;
                ++count;
            }

            newMesh.xMatrix[row][column] = newValues[0];
            newMesh.yMatrix[row][column] = newValues[1];
            newMesh.zMatrix[row][column] = newValues[2];
        }
    }

    return newMesh;
}