#include "ChangeSignCounter.hpp"
#include <stdexcept>
#include <limits>

void CountSignChanges::operator()(int x)
{
  const unsigned int max_unsigned_int = std::numeric_limits< unsigned int >::max();

  if (y && x != 0)
  {
    if (x / std::abs(x) != y / std::abs(y))
    {
      if (ChangeSignCounter < max_unsigned_int)
      {
        ChangeSignCounter += 1;
      }
      else
      {
        throw std::overflow_error("Overflow");
      }
    }
  }
  y = x;
}
