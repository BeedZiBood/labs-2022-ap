#include "subarray.h"

size_t countSequenceSimilar(const int *array, const size_t size)
{
  size_t max = 0;
  size_t counter = 1;

  for (size_t i = 1; i < size; i++)
  {
    if (array[i - 1] == array[i])
    {
      counter++;
      if (counter > max)
      {
        max = counter;
      }
    }
    else
    {
      counter = 1;
    }
  }

  return max;
}
