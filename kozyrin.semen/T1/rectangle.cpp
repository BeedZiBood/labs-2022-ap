#include "rectangle.h"
#include <stdexcept>

Rectangle::Rectangle(point_t p1, point_t p2):
  rect_{p2.x - p1.x, p2.y - p1.y, (p2.x + p1.x) / 2, (p2.y + p1.y) / 2}
{
  if (rect_.width <= 0 || rect_.height <= 0) {
    throw std::invalid_argument("Incorrect rectangle size");
  }
}

Rectangle::Rectangle(rectangle_t rect):
  rect_(rect)
{}

double Rectangle::getArea() const
{
  return rect_.width * rect_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rect_;
}

void Rectangle::move(point_t point)
{
  rect_.pos = point;
}

void Rectangle::move(double dx, double dy)
{
  addVector(rect_.pos, {dx, dy});
}

void Rectangle::scale(double k)
{
  rect_.width *= k;
  rect_.height *= k;
}

Shape* Rectangle::clone()
{
  return new Rectangle(rect_);
}
