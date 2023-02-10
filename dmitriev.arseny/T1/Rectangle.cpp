#include "Rectangle.h"
#include <stdexcept>

Rectangle::Rectangle(point_t leftBott, point_t rightTop) :
  rect(makeNewRect(leftBott, rightTop))
{
  if (rect.height <= 0 || rect.width <= 0)
  {
    throw std::exception("invalid arguments");
  }
}

double Rectangle::getArea() const
{
  return rect.height * rect.width;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rect;
}

void Rectangle::move(double dx, double dy)
{
  rect.center.x = rect.center.x + dx;
  rect.center.y = rect.center.y + dy;
}

void Rectangle::move(point_t newPos)
{
  double dx = newPos.x - rect.center.x;
  double dy = newPos.y - rect.center.y;
  move(dx, dy);
}

void Rectangle::scale(double k)
{
  if (k < 0)
  {
    throw std::exception("invalid argument");
  }
  rect.height = rect.height * k;
  rect.width = rect.width * k;
}

Shape* Rectangle::clone()
{
  point_t leftBott{ rect.center.x - rect.width / 2, rect.center.y - rect.height / 2 };
  point_t rightTop{ rect.center.x + rect.width / 2, rect.center.y + rect.height / 2 };
  return new Rectangle{ leftBott, rightTop };
}
