#include "maxLengthDescSeq.h"
#include <cstddef>

void countMaxLengthDescSeq(int value, int& predValue, size_t& length, size_t& maxLength)
{
  if (predValue > value)
  {
    length++;
    maxLength = maxLength < length ? length : maxLength;
  }
  else
  {
    maxLength = maxLength < length ? length : maxLength;
    length = 1;
  }
  predValue = value;
}
