#include "countequalelements.h"

void countEqualElements(int& value, int& pred_value, int& equal_element_counter, int& max_equal_element)
{
  if (value == pred_value)
  {
    equal_element_counter++;
    if (equal_element_counter > max_equal_element)
    {
      max_equal_element = equal_element_counter;
    }
  }
  else
  {
    equal_element_counter = 1;
  }
}
