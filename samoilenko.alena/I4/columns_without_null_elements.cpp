#include "columns_without_null_elements.h"

size_t countColumnsWithoutNull(const int* matrix, size_t row, size_t col)
{
  size_t count = 0;
  for (size_t i = 0; i < col; i++)
  {
    bool colWithoutNull = false;
    for (size_t j = 0; j < row; j++)
    {
      if (matrix[col * j + i] != 0)
      {
        colWithoutNull = true;
      }
    }
    if (!colWithoutNull)
    {
      count++;
    }
  }
  return count;
}
