#include "rectangle.h"
#include "base_functions.h"
dimkashelk::Rectangle::Rectangle(rectangle_t rectangle):
  rectangle_(rectangle)
{}
dimkashelk::Rectangle::Rectangle(point_t point_1, point_t point_2):
  rectangle_(makeRectangle(point_1, point_2))
{}
double dimkashelk::Rectangle::getArea() const
{
  return rectangle_.width * rectangle_.height;
}
dimkashelk::rectangle_t dimkashelk::Rectangle::getFrameRect() const
{
  return rectangle_;
}
void dimkashelk::Rectangle::move(point_t point)
{
  rectangle_.pos = point;
}
void dimkashelk::Rectangle::move(double delta_x, double delta_y)
{
  rectangle_.pos.x += delta_x;
  rectangle_.pos.y += delta_y;
}
dimkashelk::Shape* dimkashelk::Rectangle::clone() const
{
  return new Rectangle(rectangle_);
}
void dimkashelk::Rectangle::unsafeScale(double k) noexcept
{
  rectangle_.width *= k;
  rectangle_.height *= k;
}
