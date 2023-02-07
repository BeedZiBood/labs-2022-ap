#include "CountIndenticalElements.h"

size_t countIndenticalElements(const int* arr, size_t sizeArr)
{
  int maxCount = 0;
  int count = 1;
  for (size_t i = 0; i  < sizeArr - 1; ++i)
  {
    if (arr[i] == arr[i + 1])
    {
      count++;
    } else
    {
      count = 1;
    }
    if (count > maxCount)
    {
      maxCount = count;
    }
  }
  return maxCount;
}