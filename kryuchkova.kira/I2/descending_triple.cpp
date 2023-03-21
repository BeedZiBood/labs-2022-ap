#include "descending_triple.h"

size_t countDescendingTriple(const int *array, const size_t size)
{
  size_t counter = 0;

  for (size_t i = 2; i < size; i++)
  {
    if (array[i - 2] > array[i - 1] && array[i - 1] > array[i])
    {
      counter++;
    }
  }

  return counter;
}
