#include "PifTrio.hpp"
#include <stdexcept>
#include <limits>

void FindPifTrio::operator()(int x)
{
  const unsigned int max_unsigned_int = std::numeric_limits< unsigned int >::max();

  if (x > 0 && y > 0 && z > 0 && z * z + y * y == x * x)
  {
    if (PifCounter < max_unsigned_int)
    {
      PifCounter += 1;
    }
    else
    {
      throw std::overflow_error("Overflow");
    }
  }
  z = y;
  y = x;
}
