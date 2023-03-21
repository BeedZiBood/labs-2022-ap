#include "countMonoIncreaceLines.h"
#include <cstddef>

size_t countMonoIncreaceLines(const int* matrix, size_t line, size_t column)
{
  size_t count = 0;
  bool elNotIncreace = false;
  for (size_t i = 0; i < line; i++)
  {
    elNotIncreace = false;
    for (size_t j = 1; j < column; j++)
    {
      if (matrix[column * i + j] < matrix[column * i + (j - 1)])
      {
        elNotIncreace = true;
      }
    }
    if (!elNotIncreace)
    {
      count++;
    }
  }

  return count;
}
