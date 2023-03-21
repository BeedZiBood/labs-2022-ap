#include "counter_even_elements.h"
#include <limits>
#include <stdexcept>
void CounterEvenElements::operator()(int next)
{
  constexpr unsigned int max_int = std::numeric_limits< unsigned int >::max();
  if (prev % 2 == 0 && next % 2 == 0)
  {
    if (count == max_int)
    {
      throw std::overflow_error("A lot of numbers");
    }
    count++;
  }
  else
  {
    if (count > maxcount)
    {
      maxcount = count;
    }
    count = 0;
  }
  prev = next;
}
