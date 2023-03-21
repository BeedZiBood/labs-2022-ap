#include "arccos.h"
#include <iomanip>
#include <cmath>
#include <stdexcept>

double countArccos(double x, double absError, unsigned maxnumber)
{
  findMemberOfRow findMemberOfRow(x);
  double res = 0.0;
  double member = 0.0;
  unsigned count = 0;
  while (member > absError && count < maxnumber)
  {
    res += member;
    member = findMemberOfRow();
    count++;
  }
  return res;
}

findMemberOfRow::findMemberOfRow(double x):
  x(x),
  factorialinnumerator(1),
  number(1),
  factorialindeminator(2),
  countmembers(0)
{
  if (x < -1 || x > 1)
  {
    throw std::invalid_argument("error");
  }
}

double findMemberOfRow::operator()()
{
  double pi = 3.14;
  if (countmembers == 0)
  {
    countmembers++;
    return pi / 2;
  }
  if (countmembers == 1)
  {
    countmembers++;
    return -x;
  }
  if (countmembers == 2)
  {
    countmembers++;
    return (x * x * x) / 6;
  }
  factorialinnumerator *= number + 2;
  number++;
  factorialindeminator *= number + 2;
  number++;
  return (factorialinnumerator * pow(x, number + 4)) / factorialindeminator * (number + 2);
}
