#include "ring.h"
#include <stdexcept>

Ring::Ring(point_t center, double externalRadius, double internalRadius):
  center(center),
  internalRadius(internalRadius),
  externalRadius(externalRadius)
{
  if (externalRadius < internalRadius)
  {
    throw std::invalid_argument("invalid arguments");
  }
  if (internalRadius <= 0.0)
  {
    throw std::invalid_argument("invalid arguments");
  }
}

double Ring::getArea() const
{
  double pi = 3.141592653589793;
  return pi * externalRadius * externalRadius - pi * internalRadius * internalRadius;
}

rectangle_t Ring::getFrameRect() const
{
  point_t leftBott{center.x - externalRadius, center.y - externalRadius};
  point_t rightTop{center.x + externalRadius, center.y + externalRadius};
  return makeNewRect(leftBott, rightTop);
}

void Ring::move(double dx, double dy)
{
  center.x = center.x + dx;
  center.y = center.y + dy;
}

void Ring::move(point_t newPos)
{
  move(newPos.x - center.x, newPos.y - center.y);
}

void Ring::unsafeScale(double k)
{
  externalRadius = externalRadius * k;
  internalRadius = internalRadius * k;
}

Shape* Ring::clone() const
{
  return new Ring{center, externalRadius, internalRadius};
}
