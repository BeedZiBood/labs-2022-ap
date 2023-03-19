#include "arctan.h"

double arctan(double x, double absError, unsigned maxNumber)
{
  if (std::abs(x) > 1)
  {
    throw std::out_of_range("x must be within the range of (-1, 1)");
  }

  double result = x;
  double term = x;
  unsigned n = 1;
  while (n < maxNumber)
  {
    double nextTerm = std::pow(-1, n) * std::pow(x, 2 * n + 1) / (2 * n + 1);
    if (std::abs(nextTerm) <= absError)
    {
      break;
    }
    term = nextTerm;
    result += term;
    n++;
  }

  if (std::abs(term) > absError)
  {
    throw std::runtime_error("Maximum term count reached, but desired precision could not be achieved.");
  }
  return result;
}
