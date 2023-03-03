#include "countGrowingElements.h"
#include <iostream>

size_t countGrowingElements(const int* matrix, size_t line, size_t column)
{
  size_t counter = 0;
  for (size_t i = 0; i < line; i++)
  {
    size_t counter_in_line = 0;
    for (size_t j = 0; j < column - 1; j++)
    {
      size_t order1 = i * column + j;
      if (matrix[order1] < matrix[order1 + 1])
      {
        counter_in_line++;
      }
    }
    if (counter_in_line == column - 1)
    {
      counter++;
    }
  }
  return counter;
}
