#include "rectangle.h"
#include <stdexcept>
#include "supportFunctions.h"

Rectangle::Rectangle(const point_t &point1, const point_t &point2):
  rect_{point2.x - point1.x, point2.y - point1.y, {(point1.x + point2.x) * 0.5, (point1.y + point2.y) * 0.5}}
{
  if (point1.x >= point2.x || point1.y >= point2.y) {
    throw std::invalid_argument("Wrong rectangle input");
  }
}

double Rectangle::getArea() const
{
  return rect_.width * rect_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rect_;
}

void Rectangle::move(double dx, double dy)
{
  movePoint(rect_.pos, dx, dy);
}

void Rectangle::move(const point_t &pos)
{
  rect_.pos = pos;
}

void Rectangle::scale(double k)
{
  if (k <= 0) {
    throw std::invalid_argument("Ratio must be greater than 0");
  }
  rect_.width *= k;
  rect_.height *= k;
}
