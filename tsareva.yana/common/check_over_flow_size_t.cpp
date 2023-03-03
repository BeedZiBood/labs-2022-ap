#include "check_over_flow_size_t.h"
#include <limits>

bool checkOverFlowSizeT(size_t first_addend, size_t second_addend)
{
  size_t max_size_t = std::numeric_limits< size_t>::max();
  return (max_size_t - second_addend >= first_addend);
}
