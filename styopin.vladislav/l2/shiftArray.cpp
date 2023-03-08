#include "shiftArray.h"
#include <utility>

void reverse(int* ms, size_t rev)
{
  for (size_t i = 0, j = rev - 1; i < (rev + 1) / 2; i++, j--)
  {
    std::swap(ms[i], ms[j]);
  }
}

int* shiftArray(int* array, size_t size, size_t shift)
{
  size_t current_shifts = 0;
  while (current_shifts++ < shift)
  {
    int temp = array[0];
    for (size_t i = 0; i < size - 1; ++i)
    {
      array[i] = array[i + 1];
    }
    array[size - 1] = temp;
  }
  return array;
}
