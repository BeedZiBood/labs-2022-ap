#include "countIndices.h"
#include <limits>

size_t countIndices(const int *input_array, size_t array_size)
{
  if (array_size == 0)
  {
    return 0;
  }
  int min = std::numeric_limits< int >::max();
  int max = std::numeric_limits< int >::min();
  for (size_t i = 0; i < array_size; i++)
  {
    if (input_array[i] < min)
    {
      min = input_array[i];
    }
    if (input_array[i] > max)
    {
      max = input_array[i];
    }
  }
  return min + max;
}
