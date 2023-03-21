#include "cnt_prev_devisor.h"
#include <limits>
#include <stdexcept>

void CntDevPrev::operator()(int value)
{
  const unsigned int max_unsigned_int = std::numeric_limits< unsigned int >::max();
  dev_func_prev_val = dev_func_val;
  dev_func_val = value;
  if (dev_func_val && dev_func_prev_val)
  {
    if (cnt_dev > max_unsigned_int - 1 && dev_func_val % dev_func_prev_val == 0)
    {
      throw std::overflow_error("Not good");
    }
    else
    {
      cnt_dev += ((dev_func_val % dev_func_prev_val == 0) ? 1 : 0);
    }
  }
}
