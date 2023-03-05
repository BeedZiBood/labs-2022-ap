#include "SortingArrFromNegativeToPositiveVal.h"
#include <utility>

void partition(int* arr, size_t sizeArr)
{
  for (size_t i = 0; i < sizeArr; i++)
  {
    for (size_t j = 0; j < sizeArr - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }
}
