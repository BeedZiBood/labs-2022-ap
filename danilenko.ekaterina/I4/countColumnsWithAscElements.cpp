#include "countColumnsWithAscElements.h"

size_t countColumnsWithAscElements(const int* array, size_t rows, size_t columns)
{
  size_t cols_count = columns;
  for (size_t j = 0; j < rows; j++)
  {
    int prev_val = array[j * columns];
    for (size_t i = 1; i < columns; i++)
    {
      if (prev_val >= array[i + j * columns])
      {
        cols_count--;
        break;
      }
      prev_val = array[i + j * columns];
    }
  }
  return cols_count;
}
