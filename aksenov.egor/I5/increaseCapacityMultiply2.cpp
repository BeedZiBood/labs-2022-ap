#include "increaseCapacityMultiply2.h"
#include <cstddef>
#include <stdexcept>
#include <limits>
#include <IsOverflow.h>
size_t increaseCapacityMultiply2(size_t cap)
{
  const size_t max_size = std::numeric_limits< size_t >::max();
  if (isOverflow(max_size, cap, cap))
  {
    throw std::overflow_error("Size more than max");
  }
  else
  {
    return cap + cap;
  }
}
