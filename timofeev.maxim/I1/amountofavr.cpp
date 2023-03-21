#include "amountofavr.hpp"
#include <stdexcept>
#include <limits>

const unsigned int MaxForOver2 = std::numeric_limits< unsigned int >::max();

void Average::operator()(int value)
{
  curval = value;
  if (avg > bef && curval > avg)
  {
    if (counter1 >= MaxForOver2)
    {
      throw std::overflow_error("Overflow!");
    }
    else
    {
    counter1++;
    }
  }
  else
  {
    bef = avg;
    avg = curval;
  }
}
