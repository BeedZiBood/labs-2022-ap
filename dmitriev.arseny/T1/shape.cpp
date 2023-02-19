#include "shape.h"
#include <stdexcept>

void Shape::scale(double k)
{
  if (k < 0.0)
  {
    throw std::invalid_argument("invalid arguments");
  }
  unsafeScale(k);
}
