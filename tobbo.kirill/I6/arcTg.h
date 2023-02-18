#ifndef CALCARCTG_H
#define CALCARCTG_H

double calcArcTg(double x, double absError, unsigned numberMax);

class MemberOfSeries
{
public:
  explicit MemberOfSeries(double x);
  double operator()();

private:
  double x_;
  unsigned step_;
  unsigned sign_;
};

#endif
