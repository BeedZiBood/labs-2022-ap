#include "count_rows_without_zero.h"

size_t countRowsWithoutZero(const int* matrix, size_t rows, size_t columns)
{
  size_t numberOfRowsWithZero = 0;
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < columns; j++)
    {
      if (matrix[rows * i + j] == 0)
      {
        numberOfRowsWithZero++;
        break;
      }
    }
  }
  size_t numberOfRowsWithoutZero = rows - numberOfRowsWithZero;
  return numberOfRowsWithoutZero;
}
