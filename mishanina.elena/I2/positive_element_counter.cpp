#include "positive_element_counter.h"

size_t countPositiveElementsBeforeMinElement(const int* array, size_t size)
{
  if (size == 0)
  {
    return 0;
  }
  else
  {
    int min_element = array[0];
    size_t counter = 0;
    if (array[0] > 0)
    {
      counter = 1;
    }
    size_t final_value = 0;
    for (size_t i = 1;i < size;i++)
    {
      if (min_element > array[i])
      {
        min_element = array[i];
        final_value = counter;
      }
      if (array[i] > 0)
      {
        counter++;
      }
    }
    return final_value;
  }
}
