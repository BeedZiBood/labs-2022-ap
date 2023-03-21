#include <iostream>
#include "counter_even_elements.h"
#include "counter_after_maximum.h"
int main()
{
  int n = 0;
  std::cin >> n;
  CounterAfterMaximum counter1{0, n};
  CounterEvenElements counter2{0, 0, n};
  while (n && std::cin)
  {
    try
    {
      counter1(n);
      counter2(n);
    }
    catch (const std::overflow_error &e)
    {
      std::cout << e.what();
      return 2;
    }
    std::cin >> n;
  }
  if (!std::cin)
  {
    std::cout << "-_-";
    return 1;
  }
  std::cout << counter1.count << " ";
  std::cout << counter2.maxcount;
  return 0;
}
