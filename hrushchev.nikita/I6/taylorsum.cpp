#include "taylorsum.hpp"
#include "factorial.hpp"
#include <cmath>
#include <limits>
#include <stdexcept>
#include <cstddef>

double taylorSum(const double x, const size_t number_max, const double abs_error)
{
  if (std::abs(x) >= 1)
  {
    throw std::out_of_range("x must be within the range of (-1, 1)");
  }

  double result = 0;
  double error = std::numeric_limits< double >::max();
  size_t n = 0;

  while ((n < number_max) && (error > abs_error))
  {
    double term = factorial(2 * n) / (std::pow(factorial(n), 2)) * std::pow(x, 2 * n);
    error = std::abs(term);
    result += term;
    ++n;
  }
  if ((n >= number_max) && (error > abs_error))
  {
    throw std::runtime_error("The desired precision was not achieved");
  }
  return result;
}

