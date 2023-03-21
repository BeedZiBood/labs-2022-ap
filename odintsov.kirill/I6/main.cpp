#include <iostream>
#include <exception>
#include "lnPlusOneOverMinusOne.hpp"

int main()
{
  constexpr double absError = 0.00001;
  constexpr double step = 0.02;
  unsigned numberMax = 3;
  double l = 2.1;
  double r = 2.9;
  std::cin >> l >> r >> numberMax;
  if (!std::cin) {
    std::cout << "Error: Input error";
    return 1;
  }
  try {
    odintsov::outputComparisonTable(std::cout, l, r, step, absError, numberMax) << '\n';
  } catch (const std::exception& err) {
    std::cout << err.what() << '\n';
    return 1;
  }
}
