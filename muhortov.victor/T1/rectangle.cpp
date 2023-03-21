#include "rectangle.hpp"
#include <stdexcept>

Rectangle::Rectangle(point_t one, point_t two):
  rectangle({{(one.x + two.x) / 2.0, (one.y + two.y) / 2.0}, two.x - one.x, two.y - one.y})
{
  if (rectangle.width <= 0.0 || rectangle.height <= 0.0)
  {
    throw std::invalid_argument("invalid rectangle size");
  }
}

Rectangle::Rectangle(rectangle_t rectangle):
  rectangle(rectangle)
{}

double Rectangle::getArea() const
{
  return rectangle.width * rectangle.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle;
}

void Rectangle::move(point_t newpos)
{
  rectangle.pos = newpos;
}

void Rectangle::move(double delta_x, double delta_y)
{
  rectangle.pos = calculateVectorSum(rectangle.pos, delta_x, delta_y);
}

void Rectangle::scaleWithoutCheck(double k)
{
  rectangle.width *= k;
  rectangle.height *= k;
}

Shape *Rectangle::clone() const
{
  return new Rectangle(rectangle);
}
