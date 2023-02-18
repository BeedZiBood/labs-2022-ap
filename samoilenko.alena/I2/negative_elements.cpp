#include "negative_elements.h"
#include <cstddef>
size_t countNegativeElementsAfterMax(const int* array, size_t size)
{
  int maximum = array[0];
  size_t idx = 0;
  size_t counter = 0;
  for (size_t i = 0; i < size; i++)
  {
    if (array[i] > maximum)
    {
      maximum = array[i];
      idx = i;
    }
  }
  for (size_t i = idx + 1; i < size; i++)
  {
    if (array[i] < 0)
    {
      counter += 1;
    }
  }
  return counter;
}
