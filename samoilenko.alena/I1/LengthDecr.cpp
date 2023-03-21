#include "LengthDecr.h"

int lengthDecrF(int pred, int curr, int length)
{
  if (pred > curr && curr != 0 && pred != 0)
  {
    return length += 1;
  }
  else
  {
    return 1;
  }
}
