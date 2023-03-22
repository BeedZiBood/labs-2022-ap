#include "countRowsWithEqualSum.h"

int rowSum(const int* matrix, size_t numCols, size_t rowIndex)
{
  int sum = 0;
  for (size_t i = 0; i < numCols; i++)
  {
    sum += matrix[rowIndex * numCols + i];
  }
  return sum;
}

size_t countRowsWithEqualSum(const int* matrix, size_t numRows, size_t numCols)
{
  size_t count = 0;
  int rowSum1, rowSum2;
  for (size_t i = 0; i < numRows; i++)
  {
    rowSum1 = rowSum(matrix, numCols, i);
    for (size_t j = i + 1; j < numRows; j++)
    {
      rowSum2 = rowSum(matrix, numCols, j);
      if (rowSum1 == rowSum2)
      {
        count++;
      }
    }
  }
  return count;
}
