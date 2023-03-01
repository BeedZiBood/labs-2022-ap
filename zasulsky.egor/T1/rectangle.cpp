#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"
#include "shape.hpp"

zasulsky::Rectangle::Rectangle(const rectangle_t& rect):
  rect_(rect)
{}

zasulsky::Rectangle::Rectangle(const point_t& p1, const point_t& p2):
  rect_(getFrameRectFromCorners(p1, p2))
{}

double zasulsky::Rectangle::getArea() const
{
  return rect_.width * rect_.height;
}

zasulsky::rectangle_t zasulsky::Rectangle::getFrameRect() const
{
  return rect_;
}

void zasulsky::Rectangle::move(double dx, double dy)
{
  movePoint(rect_.pos, dx, dy);
}

void zasulsky::Rectangle::move(const point_t& pos)
{
  rect_.pos = pos;
}

void zasulsky::Rectangle::scale(double k)
{
  if (k <= 0.0)
  {
    throw std::invalid_argument("k should be bigger than 0.0");
  }
  rect_.width *= k;
  rect_.height *= k;
}
