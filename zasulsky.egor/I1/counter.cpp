#include "counter.hpp"
#include <stdexcept>
#include <limits>

zasulsky::SecondLargestFinder::SecondLargestFinder():
  secondLargestVal(0),
  largestVal(std::numeric_limits< int >::min())
{}

void zasulsky::SecondLargestFinder::operator()(int val)
{
  if (val == 0) {
    if (secondLargestVal == 0) {
      throw std::logic_error("Second largest value cannot be found in input stream");
    }
    return;
  }
  if (val > largestVal) {
    const int minInt = std::numeric_limits< int >::min();
    if (largestVal != minInt) {
      secondLargestVal = largestVal;
    }
    largestVal = val;
  } else if ((val > secondLargestVal) && (val < largestVal)) {
    secondLargestVal = val;
  }
}

zasulsky::FibonacciCounter::FibonacciCounter():
  count(0),
  lastVal(0),
  curVal(0)
{}

void zasulsky::FibonacciCounter::operator()(int val)
{
  if (val == 0) {
    if (lastVal == 0) {
      throw std::logic_error("Not enough values in input stream");
    }
    return;
  }
  const int maxInt = std::numeric_limits< int >::max();
  if ((curVal > 0) && (lastVal > 0) && (maxInt - lastVal < curVal)) {
    throw std::overflow_error("Sum overflow");
  }
  const int minInt = std::numeric_limits< int >::min();
  if ((curVal < 0) && (lastVal < 0) && (minInt - lastVal > curVal)) {
    throw std::underflow_error("Sum underflow");
  }
  if ((val == lastVal + curVal) && (lastVal != 0)) {
    const unsigned maxUnsigned = std::numeric_limits< unsigned >::max();
    if (count == maxUnsigned) {
      throw std::overflow_error("Too many values in input stream");
    }
    count++;
  }
  lastVal = curVal;
  curVal = val;
}
