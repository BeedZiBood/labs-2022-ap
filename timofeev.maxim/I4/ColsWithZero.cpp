#include "ColsWithZero.h"
#include  <cstddef>
#include "getValue.h"
bool isZeroInCol(const int *arr, size_t rows, size_t cols, size_t c)
{
  for (size_t i = 0; i < rows; i++)
  {
    if (getValue(arr, cols, i, c) == 0)
    {
      return true;
    }
  }
  return false;
}
size_t countColsWithZero(const int *arr, size_t r, size_t c)
{
  size_t count = 0;
  for (size_t i = 0; i < c; i++)
  {
    if (isZeroInCol(arr, r, c, i))
    {
      count++;
    }
  }
  return count;
}
