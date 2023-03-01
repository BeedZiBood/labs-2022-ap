#include "ellipse.hpp"
#include <corecrt_math_defines.h>
#include <stdexcept>
#include "base-types.hpp"

zasulsky::Ellipse::Ellipse(const point_t& center, double radiusVertical, double radiusHorizontal):
  center_(center),
  radiusVertical_(radiusVertical),
  radiusHorizontal_(radiusHorizontal)
{
  if ((radiusVertical <= 0) || (radiusHorizontal <= 0))
  {
    throw std::invalid_argument("radius should be bigger than 0");
  }
}
double zasulsky::Ellipse::getArea() const
{
  return radiusVertical_ * radiusHorizontal_ * M_PI;
}
zasulsky::rectangle_t zasulsky::Ellipse::getFrameRect() const
{
  return zasulsky::rectangle_t{ radiusHorizontal_ * 2, radiusVertical_ * 2, center_ };
}
void zasulsky::Ellipse::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}
void zasulsky::Ellipse::move(const point_t& position)
{
  center_ = position;
}
void zasulsky::Ellipse::scale(double k)
{
  radiusHorizontal_ *= k;
  radiusVertical_ *= k;
}
