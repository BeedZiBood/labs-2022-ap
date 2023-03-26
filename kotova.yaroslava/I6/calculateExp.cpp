#include "calculateExp.hpp"
double exp(double x, double absError, unsigned numberMax)
{
  double result = 0.0;
  double sum = 0.0;
  double members = 0;
  double numerator = x * (-1);
  unsigned factorial = 2;
  unsigned denominator = 1;
  do
  {
    sum = numerator / denominator;
    result += sum;
    members++;
    numerator *= x * (-1);
    denominator *= factorial;
    factorial++;
  }
  while (members != numberMax || sum > absError);
  return result;
}
