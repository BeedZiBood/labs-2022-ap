#include "triangle.h"
#include <exception>
#include <cmath>
#include <iostream>

Triangle::Triangle(point_t a, point_t b, point_t c) :
  a(a),
  b(b),
  c(c)
{
  point_t vec1{ b.x - a.x, b.y - a.y };
  point_t vec2{ c.x - b.x, c.y - b.y };
  point_t vec3{ a.x - c.x, a.y - c.y };

  center.x = (a.x + b.x + c.x) / 2;
  center.y = (a.y + b.y + c.y) / 2;

  aSide = std::sqrt(vec1.x * vec1.x + vec1.y * vec1.y);
  bSide = std::sqrt(vec2.x * vec2.x + vec2.y * vec2.y);
  cSide = std::sqrt(vec3.x * vec3.x + vec3.y * vec3.y);

  //if (!(aSide + bSide > cSide))
  //{
  //  throw std::exception("invalid arguments");
  //}
  //else if (!(bSide + cSide > aSide))
  //{
  //  throw std::exception("invalid arguments");
  //}
  //else if (!(cSide + aSide > bSide))
  //{
  //  throw std::exception("invalid arguments");
  //}
}

double Triangle::getArea()
{
  double p = (aSide + bSide + cSide) / 2;
  return std::sqrt(p * (p - aSide) * (p - bSide) * (p - cSide));
}

rectangle_t Triangle::getFrameRect()
{
  double xMin = std::min(a.x, std::min(b.x, c.x));
  double yMin = std::min(a.y, std::min(b.y, c.y));
  double xMax = std::max(a.x, std::max(b.x, c.x));
  double yMax = std::max(a.y, std::max(b.y, c.y));

  point_t leftBott{ xMin, yMin };
  point_t rightTop{ xMax, yMax };

  rectangle_t newRect = makeNewRect(leftBott, rightTop);

  return newRect;
}

void Triangle::move(double x, double y)
{
  a = shiftPoint(a, x, y);
  b = shiftPoint(b, x, y);
  c = shiftPoint(c, x, y);
}

void Triangle::move(point_t pos)
{
  double x = center.x - pos.x;
  double y = center.y - pos.y;

  move(x, y);
}

void Triangle::scale(double k)
{
  //if (k < 0)
  //{
  //  throw std::logic_error("invalid argument");
  //}
  aSide = aSide * k;
  bSide = bSide * k;
  cSide = cSide * k;

  a = multVec(center, a, k);
  b = multVec(center, b, k);
  c = multVec(center, c, k);
}

Shape* Triangle::clone() const
{
  return new Triangle(a, b, c);
}
