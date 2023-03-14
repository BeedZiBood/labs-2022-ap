#include "CountSameAsMin.h"
#include <limits>
#include <stdexcept>
#include <cstddef>
#include <IsOverflow.h>
size_t countSameAsMin(int minv, int value, size_t min_count)
{
  const size_t max_size = std::numeric_limits< size_t >::max();
  if (isOverflow(max_size, min_count, 1))
  {
    throw std::overflow_error("Size more than max");
  }
  else
  {
    if (minv != 0 && value < minv && value != 0)
    {
      minv = value;
      min_count = 0;
    }
    if (minv == value)
    {
      min_count++;
    }
    return min_count;
  }
}

