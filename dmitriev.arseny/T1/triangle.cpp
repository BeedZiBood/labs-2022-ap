#include "triangle.h"
#include <stdexcept>
#include <cmath>

Triangle::Triangle(point_t a, point_t b, point_t c):
  a(a),
  b(b),
  c(c)
{
  double aSide = makeLine(a, b);
  double bSide = makeLine(b, c);
  double cSide = makeLine(c, a);

  if (aSide + bSide == cSide)
  {
    throw std::invalid_argument("invalid argumet");
  }
  else if (bSide + cSide == aSide)
  {
    throw std::invalid_argument("invalid argumet");
  }
  else if (cSide + aSide == bSide)
  {
    throw std::invalid_argument("invalid argumet");
  }
}

double Triangle::getArea() const
{
  double aSide = makeLine(a, b);
  double bSide = makeLine(b, c);
  double cSide = makeLine(c, a);
  double p = (aSide + bSide + cSide) / 2;
  return std::sqrt(p * (p - aSide) * (p - bSide) * (p - cSide));
}

rectangle_t Triangle::getFrameRect() const
{
  point_t leftBott{std::min(a.x, std::min(b.x, c.x)), std::min(a.y, std::min(b.y, c.y))};
  point_t rightTop{std::max(a.x, std::max(b.x, c.x)), std::max(a.y, std::max(b.y, c.y))};
  return makeNewRect(leftBott, rightTop);
}

void Triangle::move(double dx, double dy)
{
  a = sumVec(a, {dx, dy});
  b = sumVec(b, {dx, dy});
  c = sumVec(c, {dx, dy});
}

void Triangle::move(point_t newPos)
{
  point_t center{(a.x + b.x + c.x) / 3, (a.y + b.y + c.y) / 3};
  move(newPos.x - center.x, newPos.y - center.y);
}

void Triangle::unsafeScale(double k)
{
  point_t center{(a.x + b.x + c.x) / 3, (a.y + b.y + c.y) / 3};
  a = multVec(center, a, k);
  b = multVec(center, b, k);
  c = multVec(center, c, k);
}

Shape* Triangle::clone() const
{
  return new Triangle{a, b, c};
}
