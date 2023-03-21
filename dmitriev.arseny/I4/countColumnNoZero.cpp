#include "countColumnNoZero.h"
#include <cstddef>

size_t countColumnNoZero(const int* matrix, size_t line, size_t column)
{
  size_t count = 0;
  bool zeroEl = false;

  for (size_t i = 0; i < column; i++)
  {
    zeroEl = false;
    for (size_t j = 0; j < line; j++)
    {
      if (matrix[column * j + i] == 0)
      {
        zeroEl = true;
      }
    }
    if (!zeroEl)
    {
      count++;
    }
  }

  return count;
}
