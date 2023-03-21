#include "fillArrayWithRandomNumbers.h"
#include <cstdlib>
#include <ctime>
int *fillArrayWithRandomNumbers(int *arr, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    arr[i] = std::rand();
  }
  return arr;
}
