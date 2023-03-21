#include "QuantitySignChange.h"
#include <stdexcept>
#include <limits>

void QuantitySignChange::operator()(int current_val)
{
  if (prev_val != 0)
  {
    if ((prev_val < 0 && current_val > 0) || (prev_val > 0 && current_val < 0))
    {
      if (sign_change == std::numeric_limits< unsigned int >::max())
      {
        throw std::overflow_error("Too many values");
      }
      sign_change++;
    }
  }
  prev_val = current_val;
}
