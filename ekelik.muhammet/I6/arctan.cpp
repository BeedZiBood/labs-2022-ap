#include "arctan.h"

#include <cmath>
#include <limits>
#include <stdexcept>

double arctan(double x, double abs_Error, size_t max_Number)
{
  if (std::abs(x) > 1)
  {
    throw std::out_of_range("x must be within the range of (-1, 1)");
  }

  double result = 0;
  double error = std::numeric_limits<double>::max();
  size_t n = 0;

  while ((n < max_Number) && (error > abs_Error))
  {
    double term = std::pow(-1, n) * std::pow(x, 2 * n + 1) / (2 * n + 1);
    error = std::abs(term);
    result += term;
    ++n;
  }

  if ((n >= max_Number) && (error > abs_Error))
  {
    throw std::runtime_error("Maximum term count reached, but desired precision could not be achieved.");
  }

  return result;
}
