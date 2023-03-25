#include "count_column_which_duplicate_elements.h"

size_t countColumnWhichDuplicateElements(const int * array, size_t row, size_t column)
{
  size_t counter_column = 0;
  bool duplicate = true;
  for (size_t i = 0; i < column; i++)
  {
    duplicate = true;
    for (size_t j = 0; j < row; j++)
    {
      for (size_t k = 0; k < row; k++)
      {
        if ((array[column * j + i] != array[column * k + i]) && j != k)
        {
          duplicate = false;
        }
      }
    }
    if (duplicate)
    {
      counter_column++;
    }
  }
  return counter_column;
}
