#include "both.h"
#include <limits>
#include <stdexcept>
#include <iostream>

void LocalMax::operator()(unsigned int currentValue)
{
  const unsigned int MaxUnInt = std::numeric_limits< unsigned int >::max();
  if (currentValue != 0 && beforePreviousValue != 0 && previousValue != 0) {
    if (previousValue > currentValue && previousValue > beforePreviousValue)
    {
      if (count == MaxUnInt)
      {
        throw std::overflow_error("Sequence too long. Error occurred.");
      }
      else
      {
        count += 1;
      }
    }
  }
  beforePreviousValue = previousValue;
  previousValue = currentValue;
}
void Equal::operator()(unsigned int currentValue)
{
  const unsigned int MaxUnInt = std::numeric_limits< unsigned int >::max();

  if (currentValue != 0 && beforePreviousValue != 0 && previousValue != 0) {
    if (previousValue > currentValue && previousValue < beforePreviousValue)
    {
      if (countV == MaxUnInt)
      {
        throw std::overflow_error("Sequence too long. Error occurred.");
      }
      else
      {
        countV += 1;
      }
    }
  }
  beforePreviousValue = previousValue;
  previousValue = currentValue;
}
