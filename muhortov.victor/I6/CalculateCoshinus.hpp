#ifndef LABS_CALCULATECOSHINUS_HPP
#define LABS_CALCULATECOSHINUS_HPP

#include <cstddef>

class NextTaylorElement
{
public:
  explicit NextTaylorElement(double x);
  double operator()();

private:
  size_t terms_counter;
  double x;
  double numerator_counter;
  unsigned int factorial;
  unsigned int previous_factorial_counter;
};

double calculateCoshinusInTaylor(double x, double abs_Error, size_t number_Max);

#endif
