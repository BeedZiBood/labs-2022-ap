#include <iostream>
#include "structure.h"

int main()
{
  int value = 0;
  values maxVal{ 0 };
  localValuesMax lMV{ 0 };
  do
  {
    std::cin >> value;
    if (!std::cin)
    {
      std::cout << "need number\n";
      return -1;
    }
    maxVal(value);
    lMV(value);
  }
  while (std::cin && value);
  //std::cout << "max value: " << maxVal.maxNum << "\n";
  //std::cout << "local max value: " << lMV.count << "\n";
  std::cout << maxVal.maxNum << std::endl;
  std::cout << lMV.count << std::endl;
  return 1;
}
