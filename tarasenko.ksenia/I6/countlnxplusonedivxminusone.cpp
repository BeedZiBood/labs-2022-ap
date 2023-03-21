#include "countlnxplusonedivxminusone.hpp"
#include <cmath>
#include <stdexcept>
#include "lnxplusonedivxminusone.hpp"

double countLnXPlusOneDivXMinusOne(double x, double absError, unsigned numberMax)
{
  double sum = 0;
  double member = 0;
  unsigned number = 1;
  LnXPlusOneDivXMinusOne ln(x);
  do
  {
    member = ln();
    sum += member;
    number++;
  }
  while (number <= numberMax && std::abs(member) > absError);
  if (number >= numberMax && std::abs(member) > absError)
  {
    throw std::invalid_argument("accuracy not achieved");
  }
  return sum;
}
