#include "increaseCapacityAdd20.h"
#include <cstddef>
#include <limits>
#include <stdexcept>
#include <IsOverflow.h>
size_t increaseCapacityAdd20(size_t cap)
{
  const size_t max_size = std::numeric_limits< size_t >::max();
  if (isOverflow(max_size, cap, 20))
  {
    throw std::overflow_error("Size more than max");
  }
  else
  {
    return cap + 20;
  }
}
