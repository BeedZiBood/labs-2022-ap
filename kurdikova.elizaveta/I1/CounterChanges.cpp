#include "CounterChanges.h"
#include <stdexcept>
#include <limits>

void counterSignChanges(unsigned int &countSignChanges, int prevVal, int current)
{
  if ((prevVal > 0 && current < 0) || (prevVal < 0 && current > 0)) {
    if (countSignChanges == std::numeric_limits< unsigned int >::max()) {
      throw std::overflow_error("Overflow");
    }
    countSignChanges++;
  }
}
