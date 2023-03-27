#ifndef ALLOCATIONANDDELETEMATRIX_H
#define ALLOCATIONANDDELETEMATRIX_H

#include <cstddef>

long long** createMatrix(size_t count_rows, size_t count_cols);
void deleteMatrix(const long long* const* matrix, size_t count_rows);

#endif
