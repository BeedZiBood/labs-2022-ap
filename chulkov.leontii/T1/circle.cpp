#include "circle.h"
#include <cmath>
#include <stdexcept>

Circle::Circle(const point_t& pos, double radius):
  pos_(pos),
  radius_(radius)
{
  if (radius_ < 0.0)
  {
    throw std::invalid_argument("Radius must be non-negative");
  }
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}
