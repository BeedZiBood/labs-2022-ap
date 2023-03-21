#include "maxCountOfEqualElements.h"
#include <cstddef>

size_t countMaxQuantityOfEqualElements(const int* arr, size_t size)
{
  size_t count = 1;
  size_t maxCount = 1;
  for (size_t i = 0; i + 1 < size; ++i)
  {
    if (arr[i] == arr[i + 1])
    {
      count++;
      maxCount = (maxCount < count ? count : maxCount);
    }
    else
    {
      count = 1;
    }
  }
  return maxCount;
}
