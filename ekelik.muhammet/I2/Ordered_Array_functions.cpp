#include "Ordered_Array_functions.h"

size_t orderedTriplesCount(const int* arr, const size_t arrSize)
{
  size_t count = 0;
  for (size_t i = 0; i < arrSize - 2; ++i)
  {
    for (size_t j = i + 1; j < arrSize - 1; ++j)
    {
      for (size_t k = j + 1; k < arrSize; ++k)
      {
        if (arr[i] < arr[j] && arr[j] < arr[k])
        {
          ++count;
        }
      }
    }
  }
  return count;
}
