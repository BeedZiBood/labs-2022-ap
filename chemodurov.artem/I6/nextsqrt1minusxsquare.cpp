#include "nextsqrt1minusxsquare.h"
#include <stdexcept>

Sqrt1MinusXSquare::Sqrt1MinusXSquare(double x):
 x_(x),
 current_(0.0),
 members_(0)
{
  if (x <= -1 || x >= 1)
  {
    throw std::out_of_range("X i out of range");
  }
}

double Sqrt1MinusXSquare::operator()()
{
  if (!members_)
  {
    current_ = 1.0;
    members_++;
    return current_;
  }
  double next = current_ * x_ * x_ * (2 * members_ - 1) / (2 * members_);
  current_ = next;
  members_++;
  return next;
}
