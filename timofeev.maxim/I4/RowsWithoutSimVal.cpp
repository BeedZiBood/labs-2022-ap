#include "RowsWithoutSimVal.h"
#include <cstddef>
#include "getValue.h"
bool isSim(const int *arr, size_t cols, size_t r)
{
  int val = 0;
  int next = 0;
  for (size_t i = 0; i < cols - 1; i++)
  {
    val = getValue(arr, cols, r, i);
    next = getValue(arr, cols, r, i + 1);
    if (val == next)
    {
      return false;
    }
  }
  return true;
}
size_t countRows(const int *arr, size_t r, size_t c)
{
  size_t count = 0;
  for (size_t i = 0; i < r; i++)
  {
    if (isSim(arr, c, i))
    {
      count++;
    }
  }
  return count;
}
