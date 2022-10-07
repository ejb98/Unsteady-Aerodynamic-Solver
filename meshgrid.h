#ifndef MESHGRID_H
#define MESHGRID_H

#include "Matrix.h"
#include <vector>
#include <tuple>

std::tuple<Matrix, Matrix> meshgrid(const std::vector<double>& xVector, const std::vector<double>& yVector);

#endif
