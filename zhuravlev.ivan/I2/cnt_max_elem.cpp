#include "cnt_max_elem.h"

size_t counterMaxElement(const int *arr, const size_t size)
{
  size_t cnt_max = 0;
  int max = 0;
  for (size_t i = 0; i < size; ++i)
  {
    if (arr[i] > max)
    {
      max = arr[i];
    }
  }
  for (size_t i = 0; i < size; ++i)
  {
    if (arr[i] == max)
    {
      cnt_max++;
    }
  }
  return cnt_max;
}
