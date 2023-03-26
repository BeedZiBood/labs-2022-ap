#include "countAmountOfRightPairs.h"
size_t countAmountOfRightPairs(const int *arr, const size_t size)
{
  size_t counter = 0;
  for (size_t i = 1; i < size; i++)
  {
    if (arr[i - 1] < arr[i])
    {
      counter++;
    }
  }
  return counter;
}
