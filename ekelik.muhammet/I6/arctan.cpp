#include "arctan.h"

double factorial(size_t n)
{
  double result = 1;
  for (size_t i = 1; i <= n; ++i)
  {
    result *= i;
  }
  return result;
}

double arctan(double x, double absError, size_t maxNumber)
{
  if (std::abs(x) > 1)
  {
    throw std::out_of_range("x must be within the range of (-1, 1)");
  }

  double result = 0;
  double error = std::numeric_limits< double >::max();
  size_t n = 0;

  while ((n < maxNumber) && (error > absError))
  {
    double term = std::pow(-1, n) * std::pow(x, 2 * n + 1) / (2 * n + 1);
    term /= factorial(2 * n + 1);
    error = std::abs(term);
    result += term;
    ++n;
  }

  if ((n >= maxNumber) && (error > absError))
  {
    throw std::runtime_error("Maximum term count reached, but desired precision could not be achieved.");
  }
  return result;
}
