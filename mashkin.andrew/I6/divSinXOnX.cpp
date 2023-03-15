#include "divSinXOnX.h"
#include <stdexcept>

double divSinXOnX(double x, double absError, size_t numberMax)
{
  DivisionSinXOnX newMembOfRow(x);
  double res = 0.0;
  double memb = 0.0;
  for (size_t i = 0; i < numberMax; i++)
  {
    memb = i % 2 ? -(newMembOfRow()) : newMembOfRow();
    res += memb;
    if (absError > memb)
    {
      return res;
    }
  }
  throw std::logic_error("you have gone beyond the maximum number of terms");
}

DivisionSinXOnX::DivisionSinXOnX(double x):
  x_(x),
  powX_(1),
  factorial_(1),
  var_(1)
{}

double DivisionSinXOnX::operator()()
{
  double memb = powX_ / factorial_;
  powX_ *= (x_ * x_);
  var_ += 2;
  factorial_ *= (var_ * (var_ - 1));
  return memb;
}
