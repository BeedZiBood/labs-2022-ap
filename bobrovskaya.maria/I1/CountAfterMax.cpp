#include "CountAfterMax.h"

void CountAfterMax::operator()(int value)
{
  if (value > max_value)
  {
    max_value = value;
    if (max_value == value)
    {
      count_after_max = 0;
    }
  }
  else
  {
    count_after_max++;
  }
}
