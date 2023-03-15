#include <iostream>
#include "print_table.h"

int main()
{
  double left_limit = 0.0;
  double right_limit = 0.0;
  unsigned members = 0;
  std::cin >> left_limit >> right_limit >> members;
  if (!std::cin || left_limit >= right_limit || left_limit < -1 || right_limit > 1)
  {
    std::cout << "Error... Incorrect arguments\n";
    return 1;
  }
  const double step = 0.02;
  const double absError = 0.00001;
  printTable(std::cout, left_limit, right_limit, step, members, absError);
  return 0;
}
