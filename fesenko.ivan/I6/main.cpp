#include <iostream>
#include "printTable.h"

int main()
{
  unsigned numberMax = 0;
  const double step = 0.01;
  const double absError = 0.0001;
  double left = 0.0;
  double right = 0.0;
  std::cin >> left >> right >> numberMax;
  if (!std::cin) {
    std::cerr << "Error while reading\n";
    return 2;
  }
  if (left > right) {
    std::cerr << "Invalid range\n";
    return 2;
  }
  try {
    printTable(std::cout, left, right, step, numberMax, absError);
  }
  catch (const std::exception &e) {
    std::cerr << e.what() << "\n";
    return 2;
  }
}
