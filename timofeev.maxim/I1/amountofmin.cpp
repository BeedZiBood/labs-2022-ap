#include "amountofmin.hpp"
#include <stdexcept>
#include <limits>

const unsigned int MaxForOver = std::numeric_limits< unsigned int >::max();

void MinValue::operator()(int value)
{
  if (min == 0)
  {
    min = value;
  }
  if (min != 0 && value < min && value != 0)
  {
    min = value;
    counter = 0;
  }
  if (min == value )
  {
    if (counter == MaxForOver)
    {
      throw std::overflow_error("Overflow");
    }
    else
    {
      counter++;
    }
  }
}
