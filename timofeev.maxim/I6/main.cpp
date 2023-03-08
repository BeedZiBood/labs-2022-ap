#include <iostream>
#include "sequence.h"
#include "table.h"
int main()
{
  const double step = 0.1;
  const double absError = 0.00001;
  double left = 0.0;
  double right = 0.0;
  unsigned numberMax = 0;
  std::cin >> left >> right >> numberMax;
  if (!std::cin)
  {
    std::cout << "Input error" << "\n";
    return 1;
  }
  try
  {
    outTable(std::cout, left, right, step, absError, numberMax);
  }
  catch (const std::exception &e)
  {
    std::cout << e.what() << "\n";
    return 1;
  }
  return 0;
}

