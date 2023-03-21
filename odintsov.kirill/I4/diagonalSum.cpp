#include "diagonalSum.hpp"
#include <cstddef>
#include <limits>
#include <stdexcept>

int odintsov::getOffDiagonalSumByPoint(const int* const* arr, size_t rows, size_t cols, size_t row, size_t col)
{
  size_t rowDistToEdge = rows - row - 1;
  size_t colDistToEdge = col;
  size_t minDistToEdge = rowDistToEdge < colDistToEdge ? rowDistToEdge : colDistToEdge;
  row += minDistToEdge;
  col -= minDistToEdge;
  int sum = 0;
  do {
    int newVal = arr[row--][col++];
    if ((newVal > 0) && (sum > 0) && (sum > std::numeric_limits< int >::max() - newVal)) {
      throw std::overflow_error("Sum overflow");
    }
    if ((newVal < 0) && (sum < 0) && (sum < std::numeric_limits< int >::min() - newVal)) {
      throw std::underflow_error("Sum underflow");
    }
    sum += newVal;
  } while (row != static_cast< size_t >(-1) && col != cols);
  return sum;
}

int odintsov::getMinOffDiagonalSum(const int* const* arr, size_t rows, size_t cols)
{
  if (rows == 0 || cols == 0) {
    return 0;
  }
  int minSum = getOffDiagonalSumByPoint(arr, rows, cols, 0, 0);
  for (size_t r = 1; r < rows; r++) {
    int newSum = getOffDiagonalSumByPoint(arr, rows, cols, r, 0);
    if (newSum < minSum) {
      minSum = newSum;
    }
  }
  for (size_t c = 1; c < cols; c++) {
    int newSum = getOffDiagonalSumByPoint(arr, rows, cols, rows - 1, c);
    if (newSum < minSum) {
      minSum = newSum;
    }
  }
  return minSum;
}
