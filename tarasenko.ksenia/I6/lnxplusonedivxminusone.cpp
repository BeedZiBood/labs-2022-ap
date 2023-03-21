#include "lnxplusonedivxminusone.hpp"
#include <stdexcept>

LnXPlusOneDivXMinusOne::LnXPlusOneDivXMinusOne(double x):
  x_(x),
  x0_(x),
  member_(0.0),
  number_(1)
{
  if (x <= 2 || x >= 3)
  {
    throw std::invalid_argument("x out the interval (2; 3)");
  }
}

double LnXPlusOneDivXMinusOne::operator()()
{
  member_ = 2 / ((2 * number_ - 1) * x_);
  x_ *= x0_ * x0_;
  number_++;
  return member_;
}
