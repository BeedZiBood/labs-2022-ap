#include "shape.hpp"
#include <stdexcept>

void tarasenko::Shape::checkCoefficient(double k) const
{
  if (k <= 0)
  {
    throw std::logic_error("the coefficient is less than zero");
  }
}
