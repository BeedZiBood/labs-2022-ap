#include "getMatrixValue.hpp"
#include <cstddef>

int odintsov::getMatrixValue(const int* arr, size_t rows, size_t, size_t row, size_t col)
{
  return arr[row * rows + col];
}
