#include "sqrtOnePlusX.h"
#include <limits>
#include <stdexcept>
#include <cstddef>

double sqrtOnePlusX(double x, double absError, unsigned numberMax)
{
  if (x <= -1 || x >= 1)
  {
    throw std::out_of_range("x must be within the range of (-1, 1)");
  }
  MemberOfRow defineNewMember(x);
  double result = 0.0;
  double member = 0.0;

  for (unsigned i = 0; i < numberMax; i++)
  {
    result = result + member;
    member = defineNewMember();
    if (std::abs(member) < absError)
    {
      return result;
    }
  }

  throw std::logic_error("the required accuracy has not been achieved");
}

MemberOfRow::MemberOfRow(double x):
  x(x),
  powX(1),
  next(1),
  member(0),
  sign(-1),
  n(0),
  oddFactorial(1),
  evenFactorial(2)
{
}

double MemberOfRow::operator()()
{
  member = powX * next;

  sign = sign * (-1);
  next = (oddFactorial * sign) / (evenFactorial);
  powX = powX * x;

  oddFactorial = oddFactorial * (2 * n + 1);
  n++;
  evenFactorial = evenFactorial * (2 * n + 2);

  return member;
}
