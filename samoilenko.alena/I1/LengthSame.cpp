#include "LengthSame.h"

int lengthSameF(int pred, int curr, int length)
{
  if (pred == curr && curr != 0)
  {
    return length += 1;
  }
  else
  {
    return 1;
  }
}
