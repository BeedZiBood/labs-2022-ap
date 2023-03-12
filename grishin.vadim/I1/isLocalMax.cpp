#include "isLocalMax.h"
int isLocalMax(int currentValue, int value1, int value2)
{
  if (currentValue != 0)
  {
    if (value1 > currentValue)
    {
      if (value1 > value2)
      {
        return  1;
      }
    }
  }
  return 0;
}
