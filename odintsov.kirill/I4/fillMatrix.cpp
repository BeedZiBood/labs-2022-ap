#include "fillMatrix.hpp"
#include <cstddef>

void odintsov::rippleFromPointFill(int* const* arr, size_t rows, size_t cols, size_t row, size_t col)
{
  for (size_t r = 0; r < rows; r++) {
    for (size_t c = 0; c < cols; c++) {
      size_t rowDist = row > r ? row - r : r - row;
      size_t colDist = col > c ? col - c : c - col;
      arr[r][c] = (colDist > rowDist ? colDist : rowDist) + 1;
    }
  }
}
