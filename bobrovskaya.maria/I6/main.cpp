#include <iostream>
#include "printTable.h"

int main()
{
  const double absError = 0.00001;
  const double step = 0.1;
  double left = 0.0;
  double right = 0.0;
  unsigned numberMax = 0;
  std::cin >> left >> right >> numberMax;

  if (!std::cin)
  {
    std::cout << "Failed to read parametr'\n";
    return 1;
  }
  if (left >= right)
  {
    std::cerr << " Incorrect interval\n";
    return 1;
  }
  printTable(std::cout, left, right, step, absError, numberMax);
}
