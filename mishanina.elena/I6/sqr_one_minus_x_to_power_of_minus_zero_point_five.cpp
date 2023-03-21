#include "sqr_one_minus_x_to_power_of_minus_zero_point_five.h"

double raiseToPower(double x, int power)
{
  if (power == 0)
  {
    return 1;
  }
  double result = 1;
  for (int i = 0; i < power; i++)
  {
    result *= x;
  }
  return result;
}

double getNumerator(unsigned currentMember)
{
  double result = 1;
  int i = 1;
  int k = currentMember - 1;
  while (k != 0)
  {
    result *= i;
    i += 2;
    k--;
  }
  return result;
}

double getDenominator(unsigned currentMember)
{
  double result = 1;
  int i = 2;
  int k = currentMember - 1;
  while (k != 0)
  {
    result *= i;
    i += 2;
    k--;
  }
  return result;
}

double sqrtOneMinusXToPowerOfMinusZeroPointFive(double x, unsigned members, double error)
{
  double result = 0.0;
  double next = 0.0;
  int power = 2;
  unsigned i = 1;
  while (i != members + 1 || next > error)
  {
    if (i == 1)
    {
      result += 1.0;
    }
    else
    {
      next = getNumerator(i) / getDenominator(i) * raiseToPower(x, power);
      result += next;
      power += 2;
    }
    i++;
  }

  if (std::abs(next) > error)
  {
    throw std::invalid_argument("ERROR: accuracy of the result does not fit the required");
  }

  return result;
}
