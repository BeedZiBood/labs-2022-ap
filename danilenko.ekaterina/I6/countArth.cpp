#include "countArth.h"
#include <stdexcept>
#include <cstdlib>
#include <cmath>

double countArth(double x, double absError, unsigned numberMax)
{
  if (x <= -1.0 || x >= 1.0)
  {
    throw std::invalid_argument("x does not belong to the interval (-1.0; 1.0)");
  }

  double result = x;
  double term = x;
  double xSquared = x;
  unsigned n = 1;

  while (n < numberMax)
  {
    xSquared *= x * x;
    term = xSquared / (2 * n + 1);
    result += term;
    n++;
  }
  if (std::abs(term) > absError)
  {
    throw std::logic_error("The required accuracy has not been achieved\n");
  }
  return result;
}
