#include "CountLarge.h"
#include <stdexcept>
#include <limits>

void CountLargest::operator()(int curr_val)
{
  if (curr_val > largest_val)
  {
    largest_val = curr_val;
    count_amount = 1;
  }
  else if (curr_val == largest_val)
  {
    if (count_amount == std::numeric_limits< unsigned >::max())
    {
      throw std::overflow_error("Overflow");
    }
    count_amount++;
  }
}
