#include "countColumnsWithUniqueElements.h"

bool isColumnUnique(const int *matrix, size_t rows, size_t column, size_t columnIndex)
{
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < rows; j++)
    {
      if (matrix[i * column + columnIndex] == matrix[j * column + columnIndex] && i != j)
      {
        return false;
      }
    }
  }
  return true;
}

size_t countColumnsWithUniqueElements(const int *matrix, size_t rows, size_t column)
{
  size_t counter = 0;
  for (size_t i = 0; i < column; i++)
  {
    if (isColumnUnique(matrix, rows, column, i))
    {
      counter++;
    }
  }
  return counter;
}
