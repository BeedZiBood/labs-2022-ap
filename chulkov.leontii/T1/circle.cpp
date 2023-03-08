#include "circle.h"
#include <cmath>
#include <stdexcept>
#include "rectangle.h"

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

rectangle_t Circle::getFrameRect() const
{
  return {pos_, 2 * radius_, 2 * radius_};
}

void Circle::move(const point_t& pos)
{
  pos_ = pos;
}

void Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Rectangle::scale(double k)
{
  if (k < 0.0)
  {
    throw std::invalid_argument("Error: Invalid scale ratio");
  }
  width_ *= k;
  height_ *= k;
}
