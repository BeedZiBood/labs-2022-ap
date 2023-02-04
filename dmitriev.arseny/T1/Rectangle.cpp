#include "rectangle.h"
#include <stdexcept>

Rectangle::Rectangle(point_t leftBott, point_t rightTop)
{
  if (leftBott.x > rightTop.x && leftBott.y > rightTop.y)
  {
    throw std::logic_error("invalid arguments");
  }
  if (leftBott.x == rightTop.x || leftBott.y == rightTop.y)
  {
    throw std::logic_error("invalid arguments");
  }
  rect = makeNewRect(leftBott, rightTop);
}

double Rectangle::getArea()
{
  return rect.height * rect.width;
}

rectangle_t Rectangle::getFrameRect()
{
  return rect;
}

void Rectangle::move(double x, double y)
{
  point_t newPos{ rect.pos.x + x, rect.pos.y + y };
  move(newPos);
}

void Rectangle::move(point_t newPos)
{
  rect.pos = newPos;
}

void Rectangle::scale(double k)
{
  if (k < 0)
  {
    throw std::logic_error("invalid argument");
  }
  rect.height = rect.height * k;
  rect.width = rect.width * k;
}

Shape* Rectangle::clone() const
{
  point_t leftBott{ rect.pos.x - rect.width / 2, rect.pos.y - rect.height / 2 };
  point_t rightTop{ rect.pos.x + rect.width / 2, rect.pos.y + rect.height / 2 };

  return new Rectangle(leftBott, rightTop);
}
