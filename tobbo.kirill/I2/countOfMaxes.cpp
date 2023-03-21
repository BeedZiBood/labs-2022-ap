#include "countOfMaxes.h"
#include <limits>

size_t countOfMaxes(const int* arr, size_t size)
{
  size_t count_maximum = 0;
  int maximum = std::numeric_limits< int >::min();
  for (size_t i = 0; i < size; i++)
  {
    if (arr[i] > maximum)
    {
      maximum = arr[i];
      count_maximum = 1;
    }
    else
    {
      if (arr[i] == maximum)
      {
        count_maximum++;
      }
    }
  }
  return count_maximum;
}
