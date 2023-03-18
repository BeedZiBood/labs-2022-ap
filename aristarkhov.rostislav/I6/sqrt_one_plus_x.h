#ifndef SQRT_ONE_PLUS_X_H
#define SQRT_ONE_PLUS_X_H

double sqrt_one_plus_x(double x, double absError, unsigned numberMax);

class MemberOfRow
{
public:
  explicit MemberOfRow(double x);
  double operator()();

private:
  double x;
  double powX;
  double next;
  double member;
  double sign;
  unsigned n;
  unsigned oddFactorial;
  unsigned evenFactorial;

};

#endif
