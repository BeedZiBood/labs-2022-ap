#include <iostream>
#include "make_table.h"
int main()
{
  const double step = 0.05;
  const double cos_error = 0.0001;
  double left_border = 0.0;
  double right_border = 0.0;
  size_t cos_members = 0;
  std::cin >> left_border >> right_border >> cos_members;
  if (!std::cin || left_border <= -1 || right_border >= 1 || right_border < left_border)
  {
    std::cout << "error";
    return 1;
  }
  printTable(std::cout, cos_error, cos_members, left_border, right_border, step);
}
