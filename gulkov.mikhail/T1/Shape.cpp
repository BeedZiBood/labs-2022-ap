#include "Shape.hpp"
#include <stdexcept>

void Shape::makeSafeScale(double k)
{
  k <= 0.0 ? throw std::invalid_argument("Scale error, invalid scale value") : makeScale(k);
}
