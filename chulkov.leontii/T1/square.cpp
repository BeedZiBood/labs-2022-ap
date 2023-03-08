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

double Square::getArea() const
{
  return side_ * side_;
}

rectangle_t Square::getFrameRect() const
{
  return {center_, side_, side_};
}

void Square::move(const point_t& newCenter)
{
  center_ = newCenter;
}

void Square::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}
