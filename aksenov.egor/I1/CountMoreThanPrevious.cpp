#include "CountMoreThanPrevious.h"
#include <limits>
#include <cstddef>
#include <stdexcept>
#include <IsOverflow.h>
size_t countMoreThanPrevious(int predv, int value, size_t compare_count)
{
  const size_t max_size = std::numeric_limits< size_t >::max();
  if (isOverflow(max_size, compare_count, 1))
  {
    throw std::overflow_error("Size more than max");
  }
  else
  {
    if (predv < value)
    {
      compare_count++;
    }
    return compare_count;
  }
}
