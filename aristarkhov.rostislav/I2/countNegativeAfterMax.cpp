#include "countNegativeAfterMax.h"

size_t countNegativeAfterMax(const int* array, size_t size)
{
  if (size > 0)
  {
    int max = array[0];
    size_t count = 0;
    for (size_t i = 1; i < size; i++)
    {
      if (max < array[i])
      {
        max = array[i];
        count = 0;
      }
      else if (array[i] < 0)
      {
        count++;
      }
    }
    return count;
  }
  else
  {
    return 0;
  }
}
