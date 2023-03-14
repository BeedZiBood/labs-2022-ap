#include "arctg.h"
#include <cmath>

double arctg(double x, double error, unsigned max_cnt)
{
  double x1 = - (1 / x);
  double summ = M_PI / 2;
  int multiplier = 1;
  unsigned cnt = 0;
  do
  {
    summ += x1;
    multiplier += 2;
    x1 *= -(1) / (multiplier * x * x);
    cnt++;
  }
  while(cnt < max_cnt || std::fabs(x) > error);

  return summ;
}
