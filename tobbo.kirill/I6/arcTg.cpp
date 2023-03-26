#include "arcTg.h"
#include <cmath>
#include <stdexcept>

double calcArcTg(double x, double absError, unsigned numberMax)
{
  MemberOfSeries calcMember(x);
  double res = 0.0;
  double member = 0.0;
  unsigned count = 0;
  do
  {
    member = calcMember();
    res += member;
    count++;
  }
  while (std::abs(member) > absError && count < numberMax);

  if (std::abs(member) > absError || count >= numberMax)
  {
    throw std::invalid_argument("Accuracy is not achieved");
  }
  return res;
}

MemberOfSeries::MemberOfSeries(double x):
  x_(x),
  step_(0),
  sign_(0)
{
  if (x < 2 || x > 3)
  {
    throw std::invalid_argument("Interval error");
  }
}

double MemberOfSeries::operator()()
{
  if (step_ == 0)
  {
    step_ = 1;
    double pi = 3.14159265358979323846;
    return pi / 2;
  }
  double res = 1 / (step_ * std::pow(x_, step_));
  step_ += 2;
  return res * (sign_++ % 2 != 0 ? 1 : -1);
}
