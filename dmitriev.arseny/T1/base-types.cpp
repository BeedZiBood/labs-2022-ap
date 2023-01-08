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
