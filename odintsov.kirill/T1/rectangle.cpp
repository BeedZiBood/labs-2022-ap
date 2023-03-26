#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"
#include "shape.hpp"

odintsov::Rectangle::Rectangle(const rectangle_t& rect):
  rect_(rect)
{}

odintsov::Rectangle::Rectangle(const point_t& p1, const point_t& p2):
  rect_(getFrameRectFromCorners(p1, p2))
{}

double odintsov::Rectangle::getArea() const
{
  return rect_.width * rect_.height;
}

odintsov::rectangle_t odintsov::Rectangle::getFrameRect() const
{
  return rect_;
}

void odintsov::Rectangle::move(double dx, double dy)
{
  movePoint(rect_.pos, dx, dy);
}

void odintsov::Rectangle::move(const point_t& pos)
{
  rect_.pos = pos;
}

void odintsov::Rectangle::scale(double k)
{
  assertValidScaling(k);
  rect_.width *= k;
  rect_.height *= k;
}

odintsov::Rectangle* odintsov::Rectangle::clone() const
{
  return new Rectangle(rect_);
}
