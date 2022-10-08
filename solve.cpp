#include "Matrix.h"
#include <Eigen/Dense>
#include <vector>
#include <cassert>

// Solve system of equations AX = B for solution vector X
std::vector<double> solve(const Matrix& A, const std::vector<double>& B)
{
    int matrixRows{ static_cast<int>(A.size()) };
    int matrixColumns{ static_cast<int>(A[0].size()) };

    int vectorRows{ static_cast<int>(B.size()) };

    assert(matrixRows == vectorRows && "solve failed, ensure number of matrix rows equals number of vector rows");

    Eigen::MatrixXd eigenA(matrixRows, matrixColumns);
    Eigen::VectorXd eigenB(vectorRows);

    // assign Matrix values to MatrixXd values
    for (int row{ 0 }; row < matrixRows; ++row)
    {
        for (int column{ 0 }; column < matrixColumns; ++column)
        {
            eigenA(row, column) = A[row][column];
        }
    }

    // assign std::vector<double> values to VectorXd values
    for (int row{ 0 }; row < vectorRows; ++row)
    {
        eigenB(row) = B[row];
    }

    Eigen::VectorXd vectorx = eigenA.bdcSvd(Eigen::ComputeThinU | Eigen::ComputeThinV).solve(eigenB);

    std::vector<double> X(vectorRows);

    // assign VectorXd values to std::vector<double> values
    for (int row{ 0 }; row < vectorRows; ++row)
    {
        X[row] = vectorx(row);
    }

    return X;
}