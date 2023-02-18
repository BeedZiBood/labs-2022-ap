#include "Positive_Repeating_Array.h"

bool isPositiveRepeatingElement(const int* arr, size_t arrSize)
{
  for (size_t i = 0; i < arrSize; ++i)
  {
    for (size_t j = i + 1; j < arrSize; ++j)
    {
      if (arr[i] > 0 && arr[i] == arr[j])
      {
        return true;
      }
    }
  }
  return false;
}
