#ifndef CALCEEXPNEGATIVEXEXP2_HPP
#define CALCEEXPNEGATIVEXEXP2_HPP

#include <cstddef>

class TaylorNextTerm
{
public:
  explicit TaylorNextTerm(double x);
  double operator()();

private:
  double x;
  double exp_numerator;
  unsigned int factorial;
  unsigned int denominator;
  size_t terms_count;
};

double calcEExpNegativeXExp2(double x, double abs_error, size_t number_max);

#endif
