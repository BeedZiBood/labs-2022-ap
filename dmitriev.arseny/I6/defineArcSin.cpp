#include "defineArcSin.h"
#include <stdexcept>

double defineArcSin(double x, double absError, unsigned numberMax)
{
  if (x * x > 1)
  {
    throw std::logic_error("x does not fall within the specified interval");
  }
  MemberOfRow defineNewMember(x);
  double result = 0.0;
  double member = 0.0;

  for (unsigned n = 0; n < numberMax; n++)
  {
    result = result + member;
    member = defineNewMember();
    if (member < absError)
    {
      return result;
    }
  }

  throw std::logic_error("the required accuracy has not been achieved");
}

MemberOfRow::MemberOfRow(double x):
  x(x),
  powX(x),
  number(1),
  factorialEven(1),
  factorialOdd(1)
{

}

double MemberOfRow::operator()()
{
  double member = 0;
  member = (factorialEven * powX) / (factorialOdd * number);

  powX = powX * x * x;
  factorialEven = factorialEven * number;
  factorialOdd = factorialOdd * (number + 1);
  number = number + 2;

  return member;
}
