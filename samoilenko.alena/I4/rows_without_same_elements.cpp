#include "rows_without_same_elements.h"

bool isSame(const int* matrix, size_t row, size_t col)
{
  for (size_t i = 0; i < col - 1; i++)
  {
    size_t dim = row * col + i;
    if (matrix[dim] != matrix[dim + 1])
    {
      return true;
    }
  }
  return false;
}

size_t countRowsWithoutSameElements(const int* matrix, size_t row, size_t col)
{
  size_t count = 0;
  for (size_t i = 0; i < row; i++)
  {
    if (isSame(matrix, i, col))
    {
      count++;
    }
  }
  return count;
}
