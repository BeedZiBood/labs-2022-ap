#include <iostream>
#include <stdexcept>
#include "printtable.h"

int main()
{
  double left = 0.0;
  double right = 0.0;
  size_t max_members = 0;
  const double max_right = 1.0;
  const double min_left = -1.0;
  std::cin >> left >> right >> max_members;
  if (!std::cin || right < left || right >= max_right || left <= min_left || !max_members)
  {
    std::cerr << "Error, check parameters\n";
    return 1;
  }
  const double error = 0.00001;
  const double step = 0.05;
  try
  {
    chemodurov::printTable(std::cout, left, right, step, max_members, error);
  }
  catch (const std::exception & e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  return 0;
}
