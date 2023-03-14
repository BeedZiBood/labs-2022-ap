#include "countGrowingElements.h"

bool isGrowingElements(const int* matrix, size_t line, size_t column)
{
  size_t counter_in_row = 0;
  for (size_t j = 0; j < column; j++)
  {
    size_t order1 = line * column + j;
    if (matrix[order1] < matrix[order1 + 1])
    {
      counter_in_row++;
    }
  }
  return counter_in_row == column - 1;
}

size_t countGrowingElements(const int* matrix, size_t line, size_t column)
{
  size_t counter = 0;
  for (size_t i = 0; i < line; i++)
  {
    if (isGrowingElements(matrix, i, column))
    {
      counter++;
    }
  }
  return counter;
}
