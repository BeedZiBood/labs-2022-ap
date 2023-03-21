#include "CounterElAfterMax.h"
#include <limits>
#include <stdexcept>

void CounterElAfterMax::operator()(int curr)
{
  const int max_int = std::numeric_limits< int >::max();
  if (curr < maxval)
  {
    if (count == max_int)
    {
      throw std::overflow_error("Overflow.");
    }
    else
    {
      count++;
    }
  }
  else
  {
    maxval = curr;
    count = 0;
  }
}
