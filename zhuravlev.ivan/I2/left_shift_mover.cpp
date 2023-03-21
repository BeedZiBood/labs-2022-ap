#include "left_shift_mover.h"
#include <cstddef>

int* leftShiftMover(int *arr, const size_t size, const size_t wanted_shift)
{
  size_t current_shifts = 0;
  while (current_shifts++ < wanted_shift)
  {
    int temp = arr[0];
    for (size_t i = 0; i < size - 1; ++i)
    {
      arr[i] = arr[i + 1];
    }
    arr[size - 1] = temp;
  }
  return arr;
}
