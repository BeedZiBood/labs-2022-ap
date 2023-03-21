#include "countrowswithnullelem.hpp"

size_t countRowsWithNullElem(const int * arr, size_t m, size_t n)
{
  size_t counter = 0;
  for (size_t i = 0; i < m; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
      if (arr[i * n + j] == 0)
      {
        counter++;
        break;
      }
    }
  }
  return counter;
}
