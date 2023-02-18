#include "MinDiagonalSum.h"

void minSumUpperHalf(const int* matrix, const size_t rows, size_t& minSum)
{
  for (size_t i = 0; i < rows - 1; i++)
  {
    size_t currentSum = 0;
    for (size_t j = 0; j <= i; j++)
    {
      currentSum += matrix[i + j * (rows - 1)];
    }
    if (minSum > currentSum)
    {
      minSum = currentSum;
    }
  }
}

void minSumLowerHalf(const int* matrix, const size_t rows, size_t& minSum)
{
  for (size_t i = 1; i < rows; i++)
  {
    size_t currentSum = 0;
    for (size_t j = 0; j < i; j++)
    {
      currentSum += matrix[rows * rows - i - j * (rows - 1)];
    }
    if (minSum > currentSum)
    {
      minSum = currentSum;
    }
  }
}

size_t minDiagonalSumParallelToSecondary(const int* matrix, const size_t rows)
{
  size_t minSum = std::numeric_limits< size_t >::max();
  minSumUpperHalf(matrix, rows, minSum);
  minSumLowerHalf(matrix, rows, minSum);
  return minSum;
}
