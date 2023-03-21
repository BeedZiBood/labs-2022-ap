#include <iostream>
#include <limits>
#include "countelaftermaxel.h"
#include "countmaxevenel.h"

int main()
{
  const int minInt = std::numeric_limits< int >::min();
  int el = 0;
  CountElAfterMaxEl countElAfterMaxEl {minInt, 0};
  CountMaxEvenEl countMaxEvenEl {0,0};
  do
  {
    std::cin >> el;
    if (std::cin)
    {
      try
      {
        countElAfterMaxEl(el);
        countMaxEvenEl(el);
      }
      catch (const std::overflow_error& err)
      {
        std::cout << err.what();
        return 1;
      }
    }
  }
  while (el && std::cin);
  if (!std::cin)
  {
    std::cout << "Error";
    return 2;
  }
  std::cout << countElAfterMaxEl.count << '\n';
  std::cout << countMaxEvenEl.maxEvenCount << '\n';
}
