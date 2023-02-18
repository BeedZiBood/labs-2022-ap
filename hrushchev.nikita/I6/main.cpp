#include <iostream>
#include <cmath>
#include <limits>
#include <stdexcept>
#include <cstddef>
#include "printtable.hpp"

int main()
{
  const double abs_error = 0.0001;
  const double step = 0.05;
  double x_start = 0.0;
  double x_end = 0.0;
  size_t number_max = 0;

  std::cin >> x_start >> x_end >> number_max;
  if (x_start > x_end)
  {
    std::cerr << "Invalid interval\n";
    return 1;
  }
  for (double x = x_start; x <= x_end; x += step)
  {
    try
    {
      printTable(std::cout, abs_error, step, x_start, x_end, number_max);
    }
    catch (const std::exception &e)
    {
      std::cerr << e.what() << "\n";
      return 1;
    }
  }
  return 0;
}

