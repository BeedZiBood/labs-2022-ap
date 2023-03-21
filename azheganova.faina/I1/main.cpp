#include <iostream>
#include "sequences.h"

int main()
{
  int previous = 0;
  Localminimals count1;
  Minsrmax count2;
  do
  {
    std::cin >> previous;
    if (!std::cin)
    {
      std::cout << "Not a number";
      return 1;
    }
    try
    {
      count1(previous);
      count2(previous);
    }
    catch (const std::overflow_error & e)
    {
      std::cout << e.what() << "\n";
      return 2;
    }
  }
  while (previous && std::cin);
  std::cout << count1.countlocalmin << '\n';
  std::cout << count2.countminsrmax << '\n';
  return 0;
}
