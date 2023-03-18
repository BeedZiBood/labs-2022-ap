#include <iostream>
#include "create_table.h"

int main()
{
  const double step = 0.1;
  const double error = 0.00001;
  const int precision = 5;
  unsigned cnt_members = 0;
  double left_border = 0.0;
  double right_border = 0.0;

  std::cin >> left_border >> right_border >> cnt_members;
  if (!std::cin || (left_border >= right_border || (left_border <= 2.0 || right_border >= 3.0)))
  {
    std::cerr << "Wrong input" << "\n";
    return 1;
  }
  createTable(std::cout, left_border, right_border, step, error, cnt_members, precision);
  return 0;
}
