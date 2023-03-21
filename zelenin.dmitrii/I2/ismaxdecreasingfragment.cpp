#include "ismaxdecreasingfragment.h"
size_t isMaxDecreasingFragment(int* array, size_t count_elements)
{
  size_t max_decreasing_fragment = 0;
  size_t decreasing_fragment_counter = 0;
  for (size_t i = 0; i + 1 < count_elements; i++)
  {
    if (array[i + 1] < array[i])
    {
      decreasing_fragment_counter++;
      if (decreasing_fragment_counter > max_decreasing_fragment)
      {
        max_decreasing_fragment = decreasing_fragment_counter;
      }
    }
    else
    {
      decreasing_fragment_counter = 1;
    }
  }
  return max_decreasing_fragment;
}
