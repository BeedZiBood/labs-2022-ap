#include "outputForArray.h"
#include <iostream>
std::ostream &outputForArray(std::ostream &out, int *arr, size_t size)
{
  if (size == 0)
  {
    throw std::length_error("Size error");
  }
  for (size_t i = 0; i <= size - 1; i++)
  {
    out << arr[i] << " ";
  }
  return out << "\n";
}
