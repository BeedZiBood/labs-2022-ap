#include <iostream>
#include <cmath>
#include "countExponent.h"
int main()
{
  const double absError = 0.01;
  const double step = 0.1;
  unsigned numberMax = 0;
  double start = 0.0;
  double end = 0.0;
  std::cin >> start >> end >> numberMax;
  if (!std::cin)
  {
    std::cerr << "input err" << "\n";
    return 2;
  }
  if (start > end)
  {
    std::cerr << "invalid range" << "\n";
    return 2;
  }
  try
  {
    for (double i = start; i <= end; i += step)
    {
      std::cout << i << " : " << (1 / pow(1 + i, 3)) << " : " << countExponent(i, absError, numberMax) << "\n";
    }
  }
  catch (...)
  {
    std::cerr << "error" << "\n";
    return 2;
  }
  return 0;
}
