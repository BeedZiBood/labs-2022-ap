#include "coshinus.h"
#include <cmath>
#include <stdexcept>
double calculateCoshinus(double x, double absError, size_t numberMax)
{
  if ((x <= -1.0) || (x >= 1.0))
  {
    throw std::invalid_argument("not in range [-1;1]");
  }
  double sum = 1.0;
  double n = 0.0;
  double next = 1.0;
  unsigned factorial = 1;
  do
  {
    if (n == 0)
    {
      n += 1;
    }
    else
    {
      next = std::pow(x, 2 * n) / (2 * (factorial * n));
      sum+= next;
      n++;
    }
  }
  while (n != numberMax);
  if (std::abs(next) > absError)
  {
    throw std::invalid_argument("absError not reached");
  }
  return sum;
}
