#include "Matrix.h"
#include "zeros.h"
#include <cmath>

Matrix calculateRotationMatrix(double roll, double pitch, double yaw)
{
    double alpha{ roll };
    double beta{ pitch };
    double gamma{ yaw };

    Matrix rotationMatrix{ zeros(3, 3) };

    rotationMatrix[0][0] = std::cos(beta) * std::cos(gamma);
    rotationMatrix[0][1] = std::sin(alpha) * std::sin(beta) * std::cos(gamma) - std::cos(alpha) * std::sin(gamma);
    rotationMatrix[0][2] = std::cos(alpha) * std::sin(beta) * std::cos(gamma) + std::sin(alpha) * std::sin(gamma);

    rotationMatrix[1][0] = std::cos(beta) * std::sin(gamma);
    rotationMatrix[1][1] = std::sin(alpha) * std::sin(beta) * std::sin(gamma) + std::cos(alpha) * std::cos(gamma);
    rotationMatrix[1][2] = std::cos(alpha) * std::sin(beta) * std::sin(gamma) - std::sin(alpha) * std::cos(gamma);

    rotationMatrix[2][0] = -std::sin(beta);
    rotationMatrix[2][1] = std::sin(alpha) * std::cos(beta);
    rotationMatrix[2][2] = std::cos(alpha) * std::cos(beta);

    return rotationMatrix;
}