#include "sequence.h"
#include<iostream>

int sequence(int count2, int currentValue2, int value1, int value2)
{
  do
  {
    std::cin >> currentValue2;
    if (currentValue2 != 0 && value1 > currentValue2 && value1 < value2)
      count2++;
    value2 = value1;
    value1 = currentValue2;
  }
  while(currentValue2 != 0);
  std::cout << count2;
}
