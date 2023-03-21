#include "LengthMax.h"

void LengthMax::operator()(int value)
{
  if (predV > value)
  {
    count++;
    if (count > length_max)
    {
      length_max = count;
    }
  }
  else
  {
    count = 1;
  }
  predV = value;
}
