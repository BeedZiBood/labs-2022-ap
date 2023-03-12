#ifndef WORKWITHIO_H
#define WORKWITHIO_H

#include <cstddef>
#include <fstream>

bool inputMatrix(long long* matrix, size_t count_rows, size_t count_cols, std::ifstream& in);
bool inputMatrix(long long* const* matrix, size_t count_rows, size_t count_cols, std::ifstream& in);
void printSpiralMatrix(const long long* const* spiral_matrix, size_t matrix_order, std::ostream& out);

#endif
