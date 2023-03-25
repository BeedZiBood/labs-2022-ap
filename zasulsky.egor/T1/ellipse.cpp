#include "ellipse.hpp"
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
zasulsky::Shape* zasulsky::Ellipse::clone() const
{
  return new zasulsky::Ellipse(center_, radiusVertical_, radiusHorizontal_);
}
double zasulsky::Ellipse::getArea() const
{
  constexpr double pi = 3.14159265358979323846;
  return radiusVertical_ * radiusHorizontal_ * pi;
}
zasulsky::rectangle_t zasulsky::Ellipse::getFrameRect() const
{
  return zasulsky::rectangle_t{ radiusHorizontal_ * 2, radiusVertical_ * 2, center_ };
}
void zasulsky::Ellipse::move(double dx, double dy)
{
  movePoint(center_, dx, dy);
}
void zasulsky::Ellipse::move(const point_t& position)
{
  center_ = position;
}
void zasulsky::Ellipse::unsafeScale(double k)
{
  radiusHorizontal_ *= k;
  radiusVertical_ *= k;
}
