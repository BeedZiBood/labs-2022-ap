#ifndef WORKWITHIO_H
#define WORKWITHIO_H

#include <cstddef>
#include <istream>
#include <ostream>

std::istream& inputMatrix(long long* matrix, size_t count_elements, std::istream& in);
std::istream& inputMatrix(long long* const* matrix, size_t count_rows, size_t count_cols, std::istream& in);
void printMatrix(const long long* const* spiral_matrix, size_t matrix_order, std::ostream& out);

#endif
