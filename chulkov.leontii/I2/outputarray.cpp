#include "outputarray.h"
#include <iostream>

std::ostream& outputArray(std::ostream& out, const int* arr, size_t size)
{
  if (size == 0)
  {
    return out;
  }
  for (size_t i = 0; i < size - 1; i++)
  {
    out << arr[i] << '\t';
  }
  return out << arr[size - 1];
}
