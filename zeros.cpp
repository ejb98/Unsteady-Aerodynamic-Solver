#include <vector>
#include <cassert>

using matrix_t = std::vector<std::vector<double>>;

matrix_t zeros(int rows, int columns)
{
	assert(rows > 0 && columns > 0 && "zeros failed, rows and columns must be greater than 0");

	matrix_t matrix(rows, std::vector<double>(columns));

	return matrix;
}