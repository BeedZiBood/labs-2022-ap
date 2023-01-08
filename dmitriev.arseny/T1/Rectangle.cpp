#include "Rectangle.h"
#include <stdexcept>

Rectangle::Rectangle(point_t left, point_t right) :
  left(left),
  right(right)
{
  if (left.x > right.x && left.y > right.y)
  {
    throw std::invalid_argument("incorrect input");
  }
}

double Rectangle::getArea() const
{
  return (right.y - left.y) * (right.x - left.x);
}

rectangle_t Rectangle::getFrameRect() const
{
  rectangle_t newRect;
  newRect.height = right.y - left.y;
  newRect.width = right.x - left.x;
  newRect.pos = countPointBetwen(right, left);

  return newRect;
}

void Rectangle::move(double dx, double dy)
{
  left = addVector(left, dx, dy);
  right = addVector(right, dx, dy);
}

void Rectangle::move(point_t newPosition)
{
  point_t shiftPoint;
  shiftPoint = countShift(getFrameRect().pos, newPosition);

  move(shiftPoint.x, shiftPoint.y);
}

void Rectangle::scale(double k)
{
  point_t center = getFrameRect().pos;
  right = multiplShift(center, right, k);
  left.x = center.x - (right.x - center.x);
  left.y = center.y - (right.y - center.y);
}
