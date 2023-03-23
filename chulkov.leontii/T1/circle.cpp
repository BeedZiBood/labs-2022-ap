#include "circle.h"
#include <stdexcept>
#include "basetype.h"

chulkov::Circle::Circle(const point_t& pos, double radius):
  pos_(pos),
  radius_(radius)
{
  if (radius_ <= 0.0)
  {
    throw std::invalid_argument("Radius must be non-negative");
  }
}

double chulkov::Circle::getArea() const
{
  double pi = 3.14159265358979323846;
  return pi * radius_ * radius_;
}

chulkov::rectangle_t chulkov::Circle::getFrameRect() const
{
  return rectangle_t{pos_, 2 * radius_, 2 * radius_};
}

void chulkov::Circle::move(const point_t& pos)
{
  pos_ = pos;
}

void chulkov::Circle::move(double dx, double dy)
{
  pos_ = movePoint(pos_, point_t{dx, dy});
}

void chulkov::Circle::unsafeScale(double k)
{
  radius_ *= k;
}

chulkov::Shape* chulkov::Circle::clone() const
{
  return new Circle(*this);
}
