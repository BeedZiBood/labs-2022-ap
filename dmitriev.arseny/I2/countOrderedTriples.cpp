#include "countOrderedTriples.h"
#include <cstddef>

size_t countOrderedTriples(const int* array, const size_t size)
{
  size_t count = 0;
  for (size_t i = 2; i < size; i++)
  {
    if (array[i] < array[i - 1])
    {
      if (array[i - 1] < array[i - 2])
      {
        count++;
      }
    }
  }
  return count;
}
