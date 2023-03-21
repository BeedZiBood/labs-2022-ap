#include <iostream>
#include <cstddef>
#include "PrintResult.hpp"

int main()
{
  size_t number_Max = 0;
  double left = 0.0;
  double right = 0.0;
  const double step = 0.01;
  const double ads_Error = 0.0001;

  std::cin >> left >> right >> number_Max;

  if (!std::cin || left > right || left <= -1.0 || right >= 1.0)
  {
    std::cerr << "Error with input\n";
    return 1;
  }

  for (double x = left; x < right; x += step)
  {
    try
    {
      print(std::cout, x, ads_Error, number_Max);
    }
    catch (const std::invalid_argument &e)
    {
      std::cerr << "Error: " << e.what();
      return 2;
    }
  }
}
