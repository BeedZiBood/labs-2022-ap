#include "findAscendingColumns.h"

bool isGrowingCol(const int *arr, size_t col, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows - 1; ++i)
  {
    size_t number = i * cols + col;
    if (arr[number] > arr[number + cols])
    {
      return false;
    }
  }
  return true;
}
size_t countGrowingCols(const int *arr, size_t rows, size_t cols)
{
  const int *intArr = arr;
  size_t counter = 0;
  for (size_t i = 0; i < cols; ++i)
  {
    if (isGrowingCol(intArr, i, rows, cols))
    {
      counter++;
    }
  }
  return counter;
}
