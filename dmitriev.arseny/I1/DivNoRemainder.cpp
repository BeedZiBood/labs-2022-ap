#include "DivNoRemainder.h"
#include <stdexcept>
#include <limits>

void DivNoRemainder::operator()(const int current)
{
  if (previous != 0 && current % previous == 0)
  {
    if (quantity == std::numeric_limits< unsigned int >::max())
    {
      throw std::overflow_error("too many val");
    }
    quantity++;
  }
  previous = current;
}

unsigned int DivNoRemainder::getResult() const
{
  return quantity;
}
