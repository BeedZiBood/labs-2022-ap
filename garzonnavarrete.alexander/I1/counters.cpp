#include "counters.h"
#include <limits>
#include <stdexcept>
CounterMoreNext::CounterMoreNext():
  count(0),
  prev(0)
{}
void CounterMoreNext::operator()(int next)
{
  const unsigned int max_int = std::numeric_limits< unsigned int >::max();
  if (prev < next && prev)
  {
    if (count == max_int)
    {
      throw std::overflow_error("Error");
    }
    count++;
  }
  prev = next;
}
CounterDecreasing::CounterDecreasing():
  count(0),
  max_count(0),
  prev(0)
{}
void CounterDecreasing::operator()(int next)
{
  const unsigned int max_int = std::numeric_limits<unsigned int>::max();
  if (prev > next && prev)
  {
    if (count == max_int)
    {
      throw std::overflow_error("Error");
    }
    count++;
  }
  else
  {
    if (count > max_count)
    {
      max_count = count;
    }
    count = 1;
  }
  prev = next;
}
