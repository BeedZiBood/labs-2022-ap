#include <iostream>
#include "calculateExp.hpp"
#include "printTable.hpp"

int main()
{
  double left = 0.0;
  double right = 0.0;
  const double step = 0.1;
  const double absError = 0.0001;
  unsigned numberMax = 0;
  std::cin >> left >> right >> numberMax;
  if (!std::cin || left >= right)
  {
    std::cout << "error";
    return 1;
  }
  printTable(std::cout, left, right, step, absError, numberMax);
}
