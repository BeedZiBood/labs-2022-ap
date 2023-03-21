#include "getMaxOffDiagonalSum.hpp"
#include <stdexcept>
#include <algorithm>
#include "matrixOperations.hpp"

int getDiagonalSum(const int* matrix, size_t rows, size_t cols, size_t diagIndex)
{
  int sum = 0;
  size_t diagRow = std::min(rows - 1, diagIndex);
  size_t diagCol = diagIndex - diagRow;
  if (diagCol >= cols) {
    throw std::invalid_argument("Diagonal does not exist");
  }
  while (diagRow > 0 && diagCol < cols - 1) {
    sum += zasulsky::getMatrixValue(matrix, rows, cols, diagRow--, diagCol++);
  }
  return sum + zasulsky::getMatrixValue(matrix, rows, cols, diagRow, diagCol);
}

int zasulsky::getMaxOffDiagonalSum(const int* matrix, size_t rows, size_t cols)
{
  int maxSum = getDiagonalSum(matrix, rows, cols, 0);
  for (size_t i = 0; i < rows + cols - 1; i++) {
    maxSum = std::max(maxSum, getDiagonalSum(matrix, rows, cols, i));
  }
  return maxSum;
}
