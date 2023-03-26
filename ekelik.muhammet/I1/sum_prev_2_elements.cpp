#include "sum_prev_2_elements.h"

void SumPrev2Elements::operator()(int prev1, int prev2, int current)
{
  if (current == (prev1 + prev2))
  {
    numEqualToSum++;
  }
}
