#include "naturalLogarithm.h"
#include <stdexcept>

double getNaturalLog(const double x, const size_t numberMax, const double absError)
{
  double result = 0;
  double member = 0;
  double divisor = x;
  size_t multiplier = 1;
  for (size_t i = 0; i < numberMax; i++)
  {
    member = 1 / (multiplier * divisor);
    result += member;
    divisor *= x * x;
    multiplier += 2;
  }
  if (std::abs(member) > absError)
  {
    throw std::logic_error("Error! The specified accuracy was not achieved");
  }
  return 2 * result;
}
