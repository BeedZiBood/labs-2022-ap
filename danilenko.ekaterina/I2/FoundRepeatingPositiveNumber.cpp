#include "FoundRepeatingPositiveNumber.h"

bool found_repeating_positive_number(const int* array, const size_t size)
{
  for (size_t i = 1; i < size; i++)
  {
    if ((array[i] == array[i - 1]) && (array[i] > 0))
    {
      return true;
    }
  }
  return false;
}
