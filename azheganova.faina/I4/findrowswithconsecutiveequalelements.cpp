#include"findrowswithconsecutiveequalelements.h"

size_t findRowsWithConsecutiveEqualElements(const int* arr, const size_t m, size_t n)
{
  size_t count = 0;
  size_t maxcount = 0;
  size_t linenumber = 0;
  for (size_t i = 0; i < m; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
      if (arr[j] == arr[j + 1])
      {
        count++;
      }
    }
    if (count > maxcount)
    {
      maxcount = count;
      linenumber = m;
    }
  }
  return linenumber;
}
