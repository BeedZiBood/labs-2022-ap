#include "calc_arcsin.h"
#include <cmath>
#include <stdexcept>

TaylorTerm::TaylorTerm(double x):
  x(x),
  numerator(x),
  denominator(1),
  number(0)
{}

double TaylorTerm::operator()()
{
  if (number == 0)
  {
    number++;
    return x;
  }
  else if (number == 1)
  {
    numerator *= x * x;
    denominator = 6;
    number++;
    return numerator / denominator;
  }
  else
  {
    numerator *= (number * 2 - 1) * x * x;
    denominator *= (number * 2) / (number * 2 + 1);
    number++;
    return numerator / denominator;
  }
}

double calcArcsin(double x, double error, size_t max_number)
{
  TaylorTerm TaylorTerm(x);
  double term = 0;
  double res = 0;
  size_t counter = 0;
  do
  {
    term = TaylorTerm();
    res += term;
    counter++;
  }
  while (counter < max_number && term > error);
  if (std::abs(term) > error)
  {
    throw std::invalid_argument("accuracy not achieved");
  }

  return res;
}
