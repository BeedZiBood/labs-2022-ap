#include "base_types.h"
#include <cmath>
point_t::point_t(double x, double y):
  x(x),
  y(y)
{}
point_t::point_t(const point_t &point):
  x(point.x),
  y(point.y)
{}
rectangle_t::rectangle_t(double x1, double y1, double x2, double y2):
  point((x1 + x2) / 2, (y1 + y2) / 2),
  width(x2 - x1),
  height(y2 - y1)
{}
rectangle_t::rectangle_t(point_t point, double width, double height):
  point(point),
  width(width),
  height(height)
{}
point_t rectangle_t::getLeftDownPoint() const
{
  return point_t(point.x - width / 2, point.y - height / 2);
}
vector_t::vector_t(double x, double y):
  x(x),
  y(y)
{}
vector_t::vector_t(point_t end, point_t start):
  vector_t(end.x - start.x, end.y - start.y)
{}
vector_t& vector_t::operator*=(double k)
{
  x *= k;
  y *= k;
  return *this;
}
double vector_t::getLength() const
{
  return sqrt(x * x + y * y);
}
line_t::line_t(point_t point1, point_t point2):
  A(point2.y - point1.y),
  B(-(point2.x - point1.x)),
  C(-B * point1.y - A * point1.x)
{}
