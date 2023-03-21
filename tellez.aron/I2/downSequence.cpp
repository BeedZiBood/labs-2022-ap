#include "downSequence.h"
size_t getDownSequence(const int *arr, size_t size)
{
  if (size == 0)
  {
    return 0;
  }
  size_t max = 0;
  size_t len = 1;
  size_t i = 0;
  while (i < size - 1)
  {
    if (arr[i + 1] < arr[i])
    {
      len++;
    }
    else
    {
      if (max < len)
      {
        max = len;
        len = 1;
      }
    }
    i++;
  }
  if (max < len)
  {
    max = len;
  }
  return max;
}
