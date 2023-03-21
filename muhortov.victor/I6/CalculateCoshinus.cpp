#include "CalculateCoshinus.hpp"
#include <cmath>
#include <stdexcept>

NextTaylorElement::NextTaylorElement(double x):
  terms_counter(0),
  x(x),
  numerator_counter(1),
  factorial(2),
  previous_factorial_counter(0)
{}

double NextTaylorElement::operator()()
{
  double result = 0;
  if (terms_counter == 0)
  {
    terms_counter++;
    return (1);
  }
  else
  {
    numerator_counter *= x * x;
    result = numerator_counter / factorial;
    previous_factorial_counter += 2;
    factorial *= (previous_factorial_counter + 1) * (previous_factorial_counter + 2);
    terms_counter++;

    return result;
  }
}

double calculateCoshinusInTaylor(double x, double abs_Error, size_t number_Max)
{
  NextTaylorElement NextTaylorElement(x);
  double temp = 0;
  double result = 0;
  size_t counter = 0;
  do
  {
    temp = NextTaylorElement();
    result += temp;
    counter++;
  }
  while (counter < number_Max);

  if (std::abs(temp) > abs_Error)
  {
    throw std::invalid_argument("accuracy is to small for usable arguments");
  }

  return result;
}
