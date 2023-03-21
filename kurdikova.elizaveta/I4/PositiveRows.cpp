#include "PositiveRows.h"

size_t getPosRowsCount(const int* matrix, const size_t rows, const size_t columns)
{
  size_t posRowsCount = 0;
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < columns; j++)
    {
      if (matrix[i * columns + j] <= 0)
      {
        break;
      }
      else if (j == columns - 1)
      {
        posRowsCount++;
      }
    }
  }
  return posRowsCount;
}
