#include "MinCount.hpp"
#include <stdexcept>
#include <limits>

void MinCount::operator()(int value)
{
  const int min_int = std::numeric_limits< int >::max();

  if (minvaluecounter == min_int)
  {
    throw std::overflow_error("Overflow!");
  }
  if (minvalue == 0)
  {
    minvalue = value;
  }
  if (value != 0 && value < minvalue)
  {
    minvalue = value;
    minvaluecounter = 0;
  }
  if (value == minvalue)
  {
    minvaluecounter++;
  }
}
