#include "calculateTheExponent.h"
#include <stdexcept>
#include <cmath>

double calculateTheExponent(double absError, double x, unsigned numberMax)
{
  double result = 1.0;
  double sum = 0.0;
  double dividend = x * x * (-1);
  unsigned divisor = 1;
  unsigned members = 1;
  do
  {
    sum = dividend / divisor;
    result += sum;
    members++;
    dividend *= x * x * (-1);
    divisor *= members;
  }
  while (sum > absError || members < numberMax);
  if (std::abs(sum) > absError)
  {
    throw std::logic_error("The required accuracy has not been achieved\n");
  }
  return result;
}
