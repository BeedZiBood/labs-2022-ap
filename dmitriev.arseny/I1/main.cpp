#include "DivNoRemainder.h"
#include "MaxMono.h"
#include <iostream>

int main()
{
  int current = 0;
  MaxMono maxMono;
  DivNoRemainder divNoRemainder;

  do
  {
    std::cin >> current;
    if (!std::cin)
    {
      std::cout << "Inp error" << "\n";
      return 1;
    }
    if (current == 0)
    {
      break;
    }
    try
    {
      maxMono(current);
      divNoRemainder(current);
    }
    catch (const std::overflow_error& e)
    {
      std::cout << "Error: ";
      std::cout << e.what() << "\n";
      return 1;
    }
  }
  while (std::cin && current);

  std::cout << "max mono increace - " << maxMono.getResult() << "\n";
  std::cout << "without remainder divisible by the preceding - " << divNoRemainder.getResult() << "\n";

  return 0;
}
