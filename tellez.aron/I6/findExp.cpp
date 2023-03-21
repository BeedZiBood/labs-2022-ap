#include "findExp.h"
#include <cmath>
#include <stdexcept>

double exp(double x, double error, unsigned int numberMax)
{
  double result = 1.0;
  double term = 1.0;
  double termError = 1.0;
  unsigned int n = 1;
  while (n < numberMax && termError > error)
  {
    term *= x / n;
    result += term;
    termError = std::fabs(term / result);
    n++;
  }
  if (n > numberMax || termError > error || std::isnan(result))
  {
    throw std::runtime_error("Failed to converge to the desired accuracy");
  }
  return result;
}
