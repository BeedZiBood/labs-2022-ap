#include "CounterLocalMin.h"
#include <stdexcept>
#include <limits>

void counterMin(unsigned int &countMin, int prev, int curr, int &checking)
{
  if (checking && prev < curr && curr != 0) {
    if (countMin == std::numeric_limits< unsigned int >::max()) {
      throw std::overflow_error("Overflow");
    }
    countMin++;
  }
  if (prev > curr && prev != 0) {
    checking = 1;
  } else {
    checking = 0;
  }
}
