#include <iostream>
#include "print_result.h"

int main()
{
  const double step = 0.05;
  const double error = 0.0001;
  double left = 0.0;
  double right = 0.0;
  unsigned members = 0;
  std::cin >> left >> right >> members;
  if (!std::cin || left >= right || left <= -1.0 || right >= 1.0 || !members)
  {
    std::cerr << "ERROR: invalid parameters\n";
    return 1;
  }
  for (double x = left; x < right; x += step)
  {
    try
    {
      printResult(std::cout, x, members, error);
    }
    catch (const std::exception& e)
    {
      std::cerr << e.what() << "\n";
      return 1;
    }
  }
  return 0;
}
