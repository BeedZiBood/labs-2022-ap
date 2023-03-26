#include "ring.hpp"
#include <stdexcept>

Ring::Ring(point_t one, double first, double second):
  rectangle({{one.x, one.y}, first * 2.0, first * 2.0}),
  r1(first),
  r2(second)
{
  if (first <= 0.0 || second <= 0.0 || first < second)
  {
    throw std::invalid_argument("invalid ring radius");
  }
}

double Ring::getArea() const
{
  return r1 * r1 * 3.141592653589793238 - r2 * r2 * 3.141592653589793238;
}

rectangle_t Ring::getFrameRect() const
{
  return rectangle;
}

void Ring::move(point_t newpos)
{
  rectangle.pos = newpos;
}

void Ring::move(double delta_x, double delta_y)
{
  rectangle.pos = calculateVectorSum(rectangle.pos, delta_x, delta_y);
}

void Ring::scaleWithoutCheck(double k)
{
  r1 *= k;
  r2 *= k;
  rectangle.width = r1 * 2.0;
  rectangle.height = r1 * 2.0;
}

Shape *Ring::clone() const
{
  return new Ring(rectangle.pos, r1, r2);
}
