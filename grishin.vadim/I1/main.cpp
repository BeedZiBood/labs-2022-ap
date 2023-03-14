#include "isSequence.h"
#include "isLocalmax.h"
#include <iostream>
int main()
{
  int currentValue = 0;
  int value1 = 0;
  int value2;
  int countOfLocalMax = 0;
  int countOfSequence = 0;
  std::cin >> currentValue;
  if (!std::cin)
  {
    std::cout << "Error, you need to type an integer\n";
    return 1;
  }
  while (currentValue != 0)
  {
    value2 = value1;
    value1 = currentValue;
    std::cin >> currentValue;
    if (!std::cin)
    {
      std::cout << "Entered incorrect value\n";
      return 1;
    }
    countOfLocalMax += isLocalMax(currentValue, value1, value2);
    countOfSequence += isSequence(currentValue, value1, value2);
  }
  std::cout << countOfLocalMax << "\n";
  std::cout << countOfSequence << "\n";
  return 0;
}
