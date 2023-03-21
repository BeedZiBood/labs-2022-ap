#include "maxLengthAfterMaxValue.h"
#include <cstddef>

void countMaxLengthAfterMaxValue(int value, int& maxValue, size_t& count, size_t& maxCount)
{
  if (value >= maxValue)
  {
    maxValue = value;
    maxCount = count < maxCount ? maxCount : count;
    count = 0;
  }
  else
  {
    count++;
    maxCount = count < maxCount ? maxCount : count;
  }
}
