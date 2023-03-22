#ifndef DIVSINXONX_H
#define DIVSINXONX_H
#include <cstddef>

double divSinXOnX(double x, double absError, size_t numberMax);
class DivisionSinXOnX
{
public:
  explicit DivisionSinXOnX(double x);
  double operator()();
private:
  double x_;
  double powX_;
  size_t factorial_;
  size_t var_;
};
#endif
