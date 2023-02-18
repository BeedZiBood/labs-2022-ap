#include "shifted_array.h"
#include <cstddef>

void moveTheArray(int* array, size_t size, size_t array_shift)
{
  for (size_t i = 0; i < array_shift; i++)
  {
    int t = array[size - 1];
    for (size_t k = size - 1; k > 0; k--)
    {
      array[k] = array[k - 1];
    }
    array[0] = t;
  }
}
