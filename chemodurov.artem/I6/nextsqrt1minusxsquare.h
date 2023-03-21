#ifndef NEXTSQRT1MINUSXSQUARE_H
#define NEXTSQRT1MINUSXSQUARE_H
#include <cstddef>

class Sqrt1MinusXSquare
{
 public:
  explicit Sqrt1MinusXSquare(double x);
  double operator()();
 private:
  double x_;
  double current_;
  size_t members_;
};

#endif
