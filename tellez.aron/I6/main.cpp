#include <iostream>
#include "findExp.h"
#include "printTable.h"

int main()
{
  double left = 0.0;
  double right = 0.0;
  const double step = 0.1;
  const double error = 0.0001;
  unsigned numberMax = 0;
  std::cin >> left >> right >> numberMax;
  if (!std::cin || left <= -1 || right >= 1 || right < left)
  {
    std::cout << "error";
    return 1;
  }
  printTable(std::cout, left, right, step, error, numberMax);
}
