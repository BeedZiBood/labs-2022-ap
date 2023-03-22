#include "positiveelements.h"
#include <cstddef>

bool containsOnlyPositive(const int* row, size_t countColumns)
{
  for (size_t column = 0; column < countColumns; column++)
  {
    if (row[column] < 0)
    {
      return false;
    }
  }
  return true;
}

size_t countPositiveOnlyRows(const int* matrix, size_t countRows, size_t countColumns)
{
  size_t count = 0;
  for (size_t row = 0; row < countRows; row++)
  {
    if (containsOnlyPositive(matrix + countColumns * row, countColumns))
    {
      count++;
    }
  }
  return count;
}
