#include "repeatElemInCols.h"
#include <cstddef>

int repeatElemInCols(const int* matrix, size_t rows, size_t cols)
{
  bool comparison = false;
  size_t county = 0;
  for (size_t i = 0; i < cols; i++)
  {
    comparison = false;
    for (size_t j = 0; j + 1 < rows; j++)
    {
      for (size_t k = j + 1; k < rows; k++)
      {
        if (matrix[cols * j + 1] == matrix[cols * k + i])
        {
          county++;
          comparison = true;
          break;
        }
      }
      if (comparison)
      {
        break;
      }
    }
  }
  return county;
}
