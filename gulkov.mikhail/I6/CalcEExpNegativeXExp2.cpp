#include "CalcEExpNegativeXExp2.hpp"
#include <cmath>
#include <stdexcept>

TaylorNextTerm::TaylorNextTerm(double x):
  x(x),
  exp_numerator(0),
  factorial(2),
  denominator(1),
  terms_count(0)
{}

double TaylorNextTerm::operator()()
{
  double fraction = 0;
  if (terms_count == 0)
  {
    terms_count++;
    return (1);
  }
  else if (terms_count == 1)
  {
    exp_numerator = x * x;
    terms_count++;
    return (-1 * exp_numerator);
  }
  else
  {
    exp_numerator *= x * x;
    denominator *= factorial++;
    fraction = exp_numerator / denominator;
    terms_count++;

    return terms_count % 2 != 0 ? fraction : (-1 * fraction);
  }
}

double calcEExpNegativeXExp2(double x, double abs_error, size_t number_max)
{
  TaylorNextTerm TaylorNextTerm(x);
  double member = 0;
  double result = 0;
  unsigned counter = 0;
  do
  {
    member = TaylorNextTerm();
    result += member;
    counter++;
  }
  while (counter < number_max);

  if (std::abs(member) > abs_error)
  {
    throw std::invalid_argument("accuracy not achieved");
  }

  return result;
}
