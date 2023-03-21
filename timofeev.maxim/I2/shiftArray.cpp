#include "shiftArray.h"
#include <cstddef>
#include <stdexcept>
void reverse(int *arr, const size_t size)
{
  int *i = arr;
  int *j = arr + size - 1;
  while (i < j)
  {
    std::swap(*i, *j);
    i++;
    j--;
  }
}
void shiftArray(int *arr, const size_t size, const unsigned k)
{
  if (size == 0)
  {
    throw std::length_error("Size error");
  }
  reverse(arr, size - k);
  reverse(arr + size - k, k);
  reverse(arr, size);
}
