#include <iostream>
#include "make_table.h"

int main()
{
  const double step = 0.05;
  const double error = 0.0001;
  double left_border = 0.0;
  double right_border = 0.0;
  unsigned members = 0;
  std::cin >> left_border >> right_border >> members;
  if (!std::cin || left_border >= right_border || left_border <= -1.0 || right_border >= 1.0)
  {
    std::cerr << "Error: false parameters";
    return 1;
  }
  printTable(std::cout, error, members, left_border, right_border, step);
  return 0;
}
