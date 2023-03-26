#ifndef SQRTONEPLUSX_H
#define SQRTONEPLUSX_H

double sqrtOnePlusX(double x, double absError, unsigned numberMax);

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
