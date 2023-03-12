#include "isSequence.h"
int isSequence(int currentValue2, int value1, int value2)
{
    if (currentValue2 != 0)
    {
      if (value1 > currentValue2)
      {
        if (value1 < value2)
        {
          return 1;
        }
      }
    }
  return 0;
}
