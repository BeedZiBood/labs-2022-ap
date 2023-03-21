#include "sequences.h"
#include <limits>
#include <stdexcept>

MaxCounter::MaxCounter():
  max(std::numeric_limits< int >::lowest()),
  count_max(0)
{}

void MaxCounter::operator()(const int current_value)
{
  if (count_max == std::numeric_limits< unsigned int >::max() && current_value == max)
  {
    throw std::overflow_error("Overflow!");
  }

  if (current_value > max)
  {
    max = current_value;
    count_max = 1;
  }
  else if (current_value == max)
  {
    count_max++;
  }
}

MinCounter::MinCounter():
  min(std::numeric_limits< int >::max()),
  count_min(0)
{}

void MinCounter::operator()(const int current_value)
{
  if (count_min == std::numeric_limits< unsigned int >::max() && current_value == min)
  {
    throw std::overflow_error("Overflow!");
  }

  if (current_value < min && current_value != 0)
  {
    min = current_value;
    count_min = 1;
  }
  else if (current_value == min)
  {
    count_min++;
  }
}
