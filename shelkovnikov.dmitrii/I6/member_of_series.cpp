#include "member_of_series.h"
#include <stdexcept>
MemberOfSeries::MemberOfSeries(double x):
  x(x),
  factorial(1),
  number(1)
{
  if (x >= 1 || x <= -1)
  {
    throw std::out_of_range("X must be in (-1; 1)");
  }
}
double MemberOfSeries::operator()()
{
  x *= x * x;
  factorial *= (number + 1) * (number + 2);
  number += 2;
  return x / factorial;
}
