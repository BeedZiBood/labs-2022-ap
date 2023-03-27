#include "duplicateRows.h"
bool areRowsEqual(const int* arr, size_t n, size_t row1, size_t row2)
{
  for (size_t i = 0; i < n; ++i)
  {
    if (arr[row1 * n + i] != arr[row2 * n + i])
    {
      return false;
    }
  }
  return true;
}
size_t countDuplicateRows(const int* arr, size_t m, size_t n)
{
  size_t count = 0;
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = i + 1; j < m; ++j)
    {
      if (areRowsEqual(arr, n, i, j))
      {
        ++count;
        break;
      }
    }
  }
  return count;
}
