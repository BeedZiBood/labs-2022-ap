#include "ElMoreThanPrev.h"
#include <stdexcept>
#include <limits>

void ElMoreThanPrev::operator()(int curr)
{
  const int max_int = std::numeric_limits< int >::max();
  if (curr > prev)
  {
    if (count == max_int)
    {
      throw std::overflow_error("Overflow.");
    }
    count++;
  }
  prev = curr;
}
