#include "Rectangle.hpp"
#include <stdexcept>

Rectangle::Rectangle(point_t one, point_t two):
  rect_({{(one.x + two.x) / 2.0, (one.y + two.y) / 2.0}, two.x - one.x, two.y - one.y})
{
  if (rect_.width <= 0.0 || rect_.height <= 0.0)
  {
    throw std::invalid_argument("Bad input, invalid rectangle size");
  }
}

Rectangle::Rectangle(rectangle_t rect_):
  rect_(rect_)
{}

double Rectangle::getArea() const
{
  return rect_.width * rect_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rect_;
}

void Rectangle::move(point_t position)
{
  rect_.pos = position;
}

void Rectangle::move(double dx, double dy)
{
  rect_.pos = addVector(rect_.pos, dx, dy);
}

void Rectangle::makeScale(double k)
{
  rect_.width *= k;
  rect_.height *= k;
}

Shape *Rectangle::clone() const
{
  return new Rectangle(rect_);
}
