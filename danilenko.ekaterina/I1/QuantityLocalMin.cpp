#include "QuantityLocalMin.h"
#include <stdexcept>
#include <limits>

void QuantityLocalMin::operator()(int current_val)
{
  if (before_prev_val != 0 && prev_val != 0)
  {
    if (before_prev_val > prev_val)
    {
      if (prev_val < current_val)
      {
        if (local_min == std::numeric_limits< unsigned int >::max())
        {
          throw std::overflow_error("Too many values");
        }
        local_min++;
      }
    }
  }
  before_prev_val = prev_val;
  prev_val = current_val;
}
