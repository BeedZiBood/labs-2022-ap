#include "shape.hpp"
#include <stdexcept>

void Shape::scaleCheck(double k)
{
  if (k <= 0.0)
  {
    throw std::invalid_argument("invalid coefficient");
  }
  scaleWithoutCheck(k);
}
