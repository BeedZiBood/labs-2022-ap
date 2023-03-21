#include "shiftArray.h"
#include <stdexcept>
#include <cstddef>

void reverse(int* ms, const size_t rev)
{
  for (size_t i = 0, j = rev - 1; i < (rev + 1) / 2; i++, j--)
  {
    std::swap(ms[i], ms[j]);
  }
}

void shiftArray(int* array, const size_t size, const size_t shift)
{
  size_t realShift = 0;
  if (size != 0)
  {
    realShift = shift % size;
    reverse(array, realShift);
    reverse(array + realShift, size - realShift);
    reverse(array, size);
  }
}
