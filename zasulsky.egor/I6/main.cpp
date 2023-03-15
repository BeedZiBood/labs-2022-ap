#include <iostream>
#include <exception>
#include "printTable.hpp"

int main()
{
  double l = -1;
  double r = 1;
  constexpr double step = 0.02;
  constexpr double absError = 0.00001;
  unsigned numberMax = 3;
  std::cin >> l >> r >> numberMax;
  if (!std::cin)
  {
    std::cout << "Error: Input error\n";
    return 1;
  }
  if (l > r)
  {
    std::cout << "Error: Boundaries set incorrectly\n";
    return 1;
  }
  try
  {
    zasulsky::printTable(std::cout, l, r, step, absError, numberMax);
    std::cout << '\n';
  }
  catch (const std::exception& err)
  {
    std::cout << err.what() << '\n';
    return 1;
  }
}
