#include <iostream>
#include <cstddef>
#include "printTable.h"

int main()
{
  double left = 0.0;
  double right = 0.0;
  size_t numberMax = 0;
  const double ABSERROR = 0.00000001;
  const double STEP = 0.1;

  try
  {
    std::cin >> left >> right >> numberMax;
    printTable(std::cout, left, right, numberMax, ABSERROR, STEP);
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << "\n";
    return 1;
  }
  return 0;
}
