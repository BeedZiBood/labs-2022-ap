#include "countExponent.h"
#include <stdexcept>
#include <cmath>
double countExponent(double x, double absError, unsigned numberMax)
{
  if (x <= -1 || x >= 1)
  {
    throw std::invalid_argument("x is invalid");
  }
  double sign = -1;
  double xInPow = 1, result = 0;
  bool termLessError = false;
  for (unsigned i = 0; i < numberMax; i++)
  {
    sign *= -1;
    int con = (i + 1) * (i + 2) / 2;
    double addend = sign * con * xInPow;
    if (std::abs(addend) < absError)
    {
      termLessError = true;
      break;
    }
    result += addend;
    xInPow *= x;
  }
  if (!termLessError)
  {
    throw std::invalid_argument("invalid numberMax");
  }
  return result;
}
