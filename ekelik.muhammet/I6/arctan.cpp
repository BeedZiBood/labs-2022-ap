#include "arctan.h"

double arctan(double x, double absError, unsigned maxNumber)
{
  if (std::abs(x) >= 1)
  {
    throw std::out_of_range("x must be within the range of (-1, 1)");
  }

  double result = 0.0;
  double term = x;
  unsigned n = 0;
  while (std::abs(term) > absError && n < maxNumber)
  {
    result += term;
    n++;
    term = std::pow(-1, n) * std::pow(x, 2 * n + 1) / (2 * n + 1);
  }

  if (n >= maxNumber)
  {
    throw std::runtime_error("Maximum term count reached, but desired precision could not be achieved.");
  }
  return result;
}
