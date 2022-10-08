#ifndef SOLVE_H
#define SOLVE_H

#include "Matrix.h"
#include <vector>

// Solve system of equations AX = B for solution vector X
std::vector<double> solve(const Matrix& A, const std::vector<double>& B);

#endif