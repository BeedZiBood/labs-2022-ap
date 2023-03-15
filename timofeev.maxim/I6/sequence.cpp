#include "sequence.h"
#include <stdexcept>
#include <cstdlib>
double countSequence(double x, double absError, unsigned numberMax)
{
  if ((x <= -1.0) || (x >= 1.0))
  {
    throw std::invalid_argument("x not in (-1:1)");
  }
  double result = 1.0;
  double next = 0.0;
  double sign = 1;
  unsigned int i = 0;
  double a = x;
  do
  {
    sign *= -1;
    next = sign * (i + 2) * (i + 3) / 2 * x;
    x *= a;
    if (std::abs(next) < absError)
    {
      return result;
    }
    result += next;
    i++;
  }
  while (i < numberMax);
  return result;
}
