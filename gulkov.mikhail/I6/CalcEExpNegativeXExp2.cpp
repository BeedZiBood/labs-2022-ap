#include "CalcEExpNegativeXExp2.hpp"

CalcEExpNegativeXExp2::CalcEExpNegativeXExp2(double x, double absError, size_t numberMax) : x(x), absError(absError), result(0),
                                                                                            factorial_of(2), exp(3),
                                                                                            terms_count(0), numberMax(numberMax)
{}

double CalcEExpNegativeXExp2::operator()()
{
  while (terms_count < numberMax)
  {
    result +=
      terms_count % 2 == 0 ? countTerm(terms_count, x, factorial_of, exp) : (-1 * countTerm(terms_count, x, factorial_of, exp));
    terms_count++;
  }

  return result;
}

double countFraction(double x, unsigned int &factorial_of, unsigned int &exp)
{
  double counted_exp_x = x;
  int factorial = 1;
  for (unsigned int i = 0; i < exp; i++)
  {
    counted_exp_x *= x;
  }
  for (unsigned int i = 1; i <= factorial_of; i++)
  {
    factorial *= static_cast< int >(i);
  }
  exp += 2;
  factorial_of++;
  return (counted_exp_x / factorial);
}

double countTerm(size_t terms_count, double x, unsigned int &factorial_of, unsigned int &exp)
{
  if (terms_count == 0)
  {
    return (1);
  }
  else if (terms_count == 1)
  {
    return (x * x);
  }
  else
  {
    return countFraction(x, factorial_of, exp);
  }
}
