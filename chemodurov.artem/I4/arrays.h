#ifndef ARRAYS_H
#define ARRAYS_H
#include <cstddef>

namespace chemodurov
{
  size_t countGrowingRows(const int * arr, size_t rows, size_t columns);
  long long calcMinSummSecondaryDiagonal(const int * arr, size_t rows, size_t columns);
}

#endif
