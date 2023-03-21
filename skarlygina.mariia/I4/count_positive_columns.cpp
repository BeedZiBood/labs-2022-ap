#include "count_positive_columns.h"
size_t countPositiveColumns(const int* array, size_t rows, size_t columns)
{
  size_t number_of_positive_columns = 0;
  if (!rows || !columns)
  {
    return 0;
  }
  for (size_t i = 0; i < columns; i++)
  {
    size_t row = 0;
    bool isPositive = true;
    while (row < rows)
    {
      if (array[columns * row + i] <= 0)
      {
        isPositive = false;
        break;
      }
      row++;
    }
    if (isPositive)
    {
      number_of_positive_columns++;
    }
  }
  return number_of_positive_columns;
}
