#include "repeatingPositiveNumbers.h"
bool isRepeatingPositiveNumbers(const int *arr, const size_t size)
{
  for (size_t i = 1; i < size; i++)
  {
    if ((arr[i] == arr[i - 1]) && (arr[i] > 0))
    {
      return true;
    }
  }
  return false;
}
