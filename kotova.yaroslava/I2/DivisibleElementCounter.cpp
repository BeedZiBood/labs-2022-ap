#include "DivisibleElementCounter.h"

size_t countDivision(const int* array, size_t size, unsigned int n)
{
  size_t cnt_div = 0;
  for (size_t i = 0; i < size; i++)
  {
    if (array[i] % n == 0)
    {
      cnt_div++;
    }
  }
  return cnt_div;
}

