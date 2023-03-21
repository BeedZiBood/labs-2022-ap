#include "unique_elements.h"

size_t countColumnsWithUniqueElements(const int *matrix, size_t rows, size_t columns)
{
  size_t counter_columns = 0;
  bool unique_flag = true;
  for (size_t i = 0; i < columns; i++)
  {
    unique_flag = true;
    for (size_t j = 0; j < rows; j++)
    {
      for (size_t k = 0; k < rows; k++)
      {
        if (matrix[j * columns + i] == matrix[k * columns + i] && j != k)
        {
          unique_flag = false;
          break;
        }
      }
    }
    if (unique_flag == true)
    {
      counter_columns++;
    }
  }
  return counter_columns;
}
