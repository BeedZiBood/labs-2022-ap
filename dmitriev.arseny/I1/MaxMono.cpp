#include "MaxMono.h"
#include <stdexcept>
#include <limits>

void MaxMono::operator()(const int current)
{
  if (previous != 0 && current > previous)
  {
    if (k == std::numeric_limits< unsigned int >::max())
    {
      throw std::overflow_error("too many val");
    }
    k++;
    if (quantity < k)
    {
      quantity = k;
    }
  }
  else
  {
    if (quantity < k)
    {
      quantity = k;
    }
    k = 0;
  }
  previous = current;
}

unsigned int MaxMono::getResult() const
{
  return quantity;
}
