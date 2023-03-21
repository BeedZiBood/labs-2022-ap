#include "count_diagonals_parallel_to_secondary_without_zero.h"

size_t countDiagonalsParallelToSecondaryWithoutZero(const int* matrix, size_t rows)
{
  size_t numberOfDiagonalsWithZero = 0;
  // above the diagonal
  for (size_t i = 0; i < rows - 1; i++)
  {
    for (size_t j = 0; j <= i; j++)
    {
      if (matrix[i + (rows - 1) * j] == 0)
      {
        numberOfDiagonalsWithZero++;
        break;
      }
    }
  }
  // under the diagonal
  for (size_t i = rows * (rows - 1) + 1; i < rows * rows; i++)
  {
    for (size_t j = 0; j <= rows * rows - 1 - i; j++)
    {
      if (matrix[i - (rows - 1) * j] == 0)
      {
        numberOfDiagonalsWithZero++;
        break;
      }
    }
  }
  size_t numberOfDiagonalsWithoutZero = (rows - 1) * 2 - numberOfDiagonalsWithZero;
  return numberOfDiagonalsWithoutZero;
}
