#include "base-types.h"

point_t countPointBetwen(point_t p1, point_t p2)
{
  point_t newPoint;
  newPoint.x = (p2.x + p1.x) / 2;
  newPoint.y = (p2.y + p1.y) / 2;

  return newPoint;
}

point_t addVector(point_t p, double dx, double dy)
{
  p.x = p.x + dx;
  p.y = p.y + dy;

  return p;
}

point_t countShift(point_t oldCenter, point_t newCenter)
{
  point_t newPoint;
  newPoint.x = newCenter.x - oldCenter.x;
  newPoint.y = newCenter.y - oldCenter.y;

  return newPoint;
}

point_t multiplShift(point_t center, point_t point, double k)
{
  point.x = k * (point.x - center.x) + center.x;
  point.y = k * (point.y - center.y) + center.y;

  return point;
}
