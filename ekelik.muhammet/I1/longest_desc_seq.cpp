#include "longest_desc_seq.h"
#include <iostream>

void LongestDescSequence::operator()(int value)
{
  if (value < max_value)
  {
    current_length++;
    longest_length = std::max(longest_length, current_length);
  }
  else
  {
    current_length = 1;
  }
  max_value = value;
}
