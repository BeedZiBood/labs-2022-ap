#include <iostream>
#include "resultTable.h"

int main()
{
  double left = 0.0;
  double right = 0.0;
  const double absError = 0.0001;
  const double step = 0.1;
  unsigned numberMax = 0;
  std::cin >> left >> right >> numberMax;
  if (!std::cin)
  {
    std::cerr << "Error during input" << '\n';
    return 1;
  }
  if (left > right)
  {
    std::cerr << "Range is not correct" << '\n';
    return 1;
  }
  try
  {
    printTable(std::cout, step, right, left, absError, numberMax);
  }
  catch (const std::exception &ex)
  {
    std::cerr << ex.what() << "\n";
    return 1;
  }
}
