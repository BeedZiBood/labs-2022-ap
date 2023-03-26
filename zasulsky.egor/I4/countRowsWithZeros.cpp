#include "countRowsWithZeros.hpp"
#include <cstddef>
#include "matrixOperations.hpp"

bool rowHasZero(const int* matrix, size_t rows, size_t cols, size_t row)
{
  for (size_t c = 0; c < cols; c++) {
    if (zasulsky::getMatrixValue(matrix, rows, cols, row, c) == 0) {
      return true;
    }
  }
  return false;
}

size_t zasulsky::countRowsWithZeros(const int* matrix, size_t rows, size_t cols)
{
  size_t rowsWithZeros = 0;
  for (size_t r = 0; r < rows; r++) {
    if (rowHasZero(matrix, rows, cols, r)) {
      rowsWithZeros++;
    }
  }
  return rowsWithZeros;
}
