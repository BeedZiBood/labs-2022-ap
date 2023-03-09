#include "iostream"
#include "LocalMax.h"

int LocalMax(int countLocalMax, int currentValue, int value1, int value2)
{
  do {
    std::cin >> currentValue;
    if (currentValue != 0 && value1 > currentValue && value1 > value2)
      countLocalMax++;
    value2 = value1;
    value1 = currentValue;
  } while (currentValue != 0);
  std::cout << countLocalMax;
}
