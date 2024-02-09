#include <iostream>
#include "sqrtOnePlusX.h"
#include "printResult.h"

int main()
{
  const double absError = 0.001;
  const double step = 0.01;
  unsigned numberMax = 0;
  double left = 0.0;
  double right = 0.0;

  std::cin >> left >> right >> numberMax;

  if (!std::cin)
  {
    std::cerr << "Error\n";
    return 1;
  }

  try
  {
    printResult(std::cout, left, right, step, absError, numberMax);
  }
  catch (const std::exception& e)
  {
    std::cout << e.what() << '\n';
    return 1;
  }
  return 0;
}