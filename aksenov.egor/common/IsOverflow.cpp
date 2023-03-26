#include "IsOverflow.h"
#include <limits>
#include <cstddef>
#include <stdexcept>
bool isOverflow(const size_t max_size, size_t number, size_t incr)
{
  if (max_size - incr <= number)
  {
    return true;
  }
  else
  {
    return false;
  }
}
