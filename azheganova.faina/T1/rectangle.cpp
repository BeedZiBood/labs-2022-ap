#include "rectangle.h"
#include <iostream>

Shape* inputRectangle(std::istream &input)
{
  double x1 = 0.0;
  double y1 = 0.0;
  double x2 = 0.0;
  double y2 = 0.0;
  input >> x1 >> y1 >> x2 >> y2;
  if (!input)
  {
    throw std::logic_error("error");
  }
  return new Rectangle(point_t{x1, y1}, point_t{x2, y2});
}

Rectangle::Rectangle(rectangle_t rectangle):
  rectangle1(rectangle)
{}
Rectangle::Rectangle(point_t point1, point_t point2):
  rectangle1(makeFrame(point1, point2))
{
  if (point1.x >= point2.x || point1.y >= point2.y)
  {
    throw std::invalid_argument("wrong rectangle");
  }
}
double Rectangle::getArea() const
{
  return rectangle1.width * rectangle1.height;
}
rectangle_t Rectangle::getFrameRect() const
{
  return rectangle1;
}
void Rectangle::move(point_t point)
{
  rectangle1.pos = point;
}
void Rectangle::move(double dx, double dy)
{
  rectangle1.pos.x += dx;
  rectangle1.pos.y += dy;
}
void Rectangle::scale(double k) noexcept
{
  rectangle1.width *= k;
  rectangle1.height *= k;
}
Shape *Rectangle::clone() const
{
  return new Rectangle(rectangle1);
}
