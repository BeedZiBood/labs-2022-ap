#include "ring.h"
#include <stdexcept>

Ring::Ring(point_t center, double externalRadius, double internalRadius) :
  center(center),
  externalRadius(externalRadius),
  internalRadius(internalRadius)
{
  if (externalRadius < internalRadius)
  {
    throw std::logic_error("invalid arguments");
  }
}

double Ring::getArea()
{
  double pi = 3.141592653589793;
  return pi * externalRadius * externalRadius - pi * internalRadius * internalRadius;
}

rectangle_t Ring::getFrameRect()
{
  point_t leftBott{ center.x - externalRadius, center.y - externalRadius };
  point_t rightTop{ center.x + externalRadius, center.y + externalRadius };

  rectangle_t newRect = makeNewRect(leftBott, rightTop);

  return newRect;
}

void Ring::move(double x, double y)
{
  center = shiftPoint(center, x, y);
}

void Ring::move(point_t pos)
{
  double x = center.x - pos.x;
  double y = center.y - pos.y;

  move(x, y);
}

void Ring::scale(double k)
{
  if (k < 0)
  {
    throw std::logic_error("invalid argument");
  }

  externalRadius = externalRadius * k;
  internalRadius = internalRadius * k;
}

Shape* Ring::clone() const
{
  return new Ring(center, externalRadius, internalRadius);
}
