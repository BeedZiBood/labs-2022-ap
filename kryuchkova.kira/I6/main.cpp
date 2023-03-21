#include <iostream>
#include <cstddef>
#include "calc_arcsin.h"
#include "print_table.h"

int main()
{
  size_t max_number = 0;
  double left = 0.0;
  double right = 0.0;
  const double step = 0.01;
  const double error = 0.00001;
  std::cin >> left >> right >> max_number;

  if (!std::cin || left < -1.0 || right > 1.0 || left > right)
  {
    std::cerr << "invalid input" << '\n';
    return 1;
  }

  try
  {
    for (double i = left; i <= right; i += step)
    {
      printTable(std::cout, i, calcArcsin(i, error, max_number));
    }
  }
  catch (const std::invalid_argument &e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }

}
