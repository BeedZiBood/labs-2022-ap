#include <iostream>
#include "counters.h"
int main()
{
  CounterMoreNext counterMoreNext;
  CounterDecreasing counterDecreasing;
  int n = 0;
  std::cin >> n;
  while (n && std::cin)
  {
    try
    {
      counterMoreNext(n);
      counterDecreasing(n);
    }
    catch (const std::overflow_error &e)
    {
      std::cout << e.what() << '\n';
      return 2;
    }
    std::cin >> n;
  }
  if (!std::cin)
  {
    std::cout << "Error" << '\n';
    return 1;
  }
  return 0;
}
