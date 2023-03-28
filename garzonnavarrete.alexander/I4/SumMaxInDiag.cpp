#include "SumMaxInDiag.h"
#include <cstddef>
int findMaxSumOfDiagonal(const int* matrix, size_t rows, size_t cols)
{
  int maxSum = 0;
  int summa = 0;
  for (size_t i = 1; i < rows; i++)
  {
    for (size_t j = 0, k = 0; j + i < cols; j++, k++)
    {
      summa += matrix[cols * j + i + k];
    }
    maxSum = summa > maxSum ? summa : maxSum;
    summa = 0;
  }
  for (size_t i = 1; i < rows; i++)
  {
    for (size_t j = i, k = 0; j < cols; j++, k++)
    {
      summa += matrix[cols * j + k];
    }
    maxSum = summa > maxSum ? summa : maxSum;
    summa = 0;
  }
  return maxSum;
}
