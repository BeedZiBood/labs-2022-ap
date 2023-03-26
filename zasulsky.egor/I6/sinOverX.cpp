#include "sinOverX.hpp"
#include <cmath>
#include <stdexcept>

double zasulsky::sinOverX(double x, double absError, unsigned numberMax)
{
  const double l = -1;
  const double r = 1;
  if ((x <= l) || (x >= r))
  {
    throw std::invalid_argument("x not in (-1;1)");
  }
  double square = x * x;
  double sum = 1;
  double next = 1;
  unsigned members = 1;
  do
  {
    next *= -(square / (members * 2)) / (members * 2 + 1);
    if (std::abs(next) < absError)
    {
      break;
    }
    sum += next;
    members++;
  }
  while (members != numberMax);
  if ((members == numberMax) && (std::abs(next) > absError))
  {
    throw std::runtime_error("absError not reached");
  }
  return sum;
}
