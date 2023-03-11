#include "circle.h"
#include <cmath>
#include <stdexcept>
#include "basetype.h"

Circle::Circle(const point_t& pos, double radius):
  pos_(pos),
  radius_(radius)
{
  if (radius_ <= 0.0)
  {
    throw std::invalid_argument("Radius must be non-negative");
  }
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return rectangle_t{pos_, 2 * radius_, 2 * radius_};
}

void Circle::move(const point_t& pos)
{
  pos_ = pos;
}

void Circle::move(double dx, double dy)
{
  pos_ = movePoint(pos_, point_t{ dx, dy });
}

void Circle::scale(double k)
{
  if (k < 0.0)
  {
    throw std::invalid_argument("Error: Invalid scale");
  }
  radius_ *= k;
}

Shape* Circle::clone() const
{
  return new Circle(*this);
}
