#include "values.h"
#include <limits>
#include <stdexcept>

void valuesRowCounter::operator()(int value)
{
  constexpr int maxValue = std::numeric_limits< int >::max();
  if (maxNum == maxValue)
  {
    throw std::overflow_error("overflow");
  }
  else if (value == predV)
  {
    nValue += 1;
  }
  else
  {
    maxNum = std::max(nValue, maxNum);
    nValue = 1;
  }
  predV = value;
}
void localValuesMax::operator()(int value)
{
  constexpr int maxLocalVal = std::numeric_limits< int >::max();
  if (value == maxLocalVal)
  {
    throw std::overflow_error("overflow");
  }
  if (pp_value && value)
  {
    if (p_value > pp_value && p_value > value)
    {
      count++;
    }
  }
  pp_value = p_value;
  p_value = value;
}
