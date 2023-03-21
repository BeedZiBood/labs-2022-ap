#include "countDecreasingValues.h"
#include <limits>
#include <stdexcept>
size_t countDecreasingValues(const int *arr, size_t size)
{
  size_t curleght = 1;
  size_t maxleght = 1;
  if (size == 0)
  {
    throw std::length_error("Size error");
  }
  for (size_t i = 1; i < size; ++i)
  {
    if (arr[i - 1] > arr[i])
    {
      curleght++;
      if (curleght > maxleght)
      {
        maxleght = curleght;
      }
    }
    if (arr[i] > arr[i - 1])
    {
      curleght = 1;
    }
  }
  return maxleght;
}
