#include "counter_after_maximum.h"
#include <limits>
#include <stdexcept>
void CounterAfterMaximum::operator()(int next)
{
  constexpr unsigned int max_int = std::numeric_limits< unsigned int >::max();
  if (next < max)
  {
    if (count == max_int)
    {
      throw std::overflow_error("error");
    }
    count++;
  }
  else
  {
    max = next;
    count = 0;
  }
}
