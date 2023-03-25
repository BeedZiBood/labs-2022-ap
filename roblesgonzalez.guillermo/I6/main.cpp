#include <iostream>
#include "make_table.h"
int main()
{
  const double step = 0.05;
  const double cos_error = 0.0001;
  double left = 0.0;
  double right = 0.0;
  size_t cos_members = 0;
  std::cin >> left >> right >> cos_members;
  if (!std::cin || left <= -1 || right >= 1 || right < left)
  {
    std::cout << "error";
    return 1;
  }
  printTable(std::cout, cos_error, cos_members, left, right, step);
}
