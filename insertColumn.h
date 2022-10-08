#ifndef INSERTCOLUMN_H
#define INSERTCOLUMN_H

#include "Matrix.h"
#include <vector>

// Note: This function directly manipulates the matrix passed in by inserting a column at the beginning
void insertColumn(const std::vector<double>& firstColumn, Matrix& matrix);

#endif