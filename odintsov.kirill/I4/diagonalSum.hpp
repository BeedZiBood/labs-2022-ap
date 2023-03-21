#ifndef DIAGONALSUM_HPP
#define DIAGONALSUM_HPP

#include <cstddef>

namespace odintsov {
  int getOffDiagonalSumByPoint(const int* const* arr, size_t rows, size_t cols, size_t row, size_t col);
  int getMinOffDiagonalSum(const int* const* arr, size_t rows, size_t cols);
}

#endif
