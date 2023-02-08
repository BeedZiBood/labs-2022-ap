#include "LOCALMAX.h"
#include <limits>
#include <stdexcept>

void LocalMax::operator()(unsigned int currentValue)
{
  const unsigned int MaxUnInt = std::numeric_limits< unsigned int >::max();
 
  if (currentValue != 0 && beforePreviousValue != 0 && previousValue != 0) {
      if (count == MaxUnInt) {
          throw std::overflow_error("Sequence too long. Error occurred.");
      }

      count += (previousValue > currentValue && previousValue > beforePreviousValue);
  }
  if (currentValue != 0 && beforePreviousValue != 0 && previousValue != 0) {
      if (count == MaxUnInt) {
          throw std::overflow_error("Sequence too long. Error occurred.");
      }
      countV += (previousValue > currentValue && previousValue < beforePreviousValue);
  }

  beforePreviousValue = previousValue;
  previousValue = currentValue;
}
