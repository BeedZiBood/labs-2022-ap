#include "square.h"
#include <stdexcept>

Square::Square(const point_t& center, double side):
  center_(center),
  side_(side)
{
  if (side_ < 0.0)
  {
    throw std::invalid_argument("Invalid side value");
  }
}
