#include "MaxElements.h"

int countMaxElements(const int* array, const size_t size)
{
  size_t count = 0;
  int max_value = array[0];
  for (size_t i = 0; i < size; i++)
  {
    if (array[i] > max_value)
    {
      max_value = array[i];
      count = 1;
    }
    else if (max_value == array[i])
    {
      count++;
    }
  }
  return count;
}
