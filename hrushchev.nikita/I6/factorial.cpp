#include "factorial.hpp"
#include <cstddef>

double factorial(const size_t n)
{
  double result = 1;
  for (size_t i = 1; i <= n; ++i)
  {
    result *= i;
  }
  return result;
}

