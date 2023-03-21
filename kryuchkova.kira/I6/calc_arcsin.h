#ifndef CALC_ARCSIN_H
#define CALC_ARCSIN_H
#include <cstddef>

class TaylorTerm
{
  public:
    TaylorTerm(double x);
    double operator()();
  private:
    double x;
    double numerator;
    int denominator;
    size_t number;
};

double calcArcsin(double x, double error, size_t max_number);

#endif
