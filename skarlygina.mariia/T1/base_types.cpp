#include "base_types.h"
#include <iostream>

point_t baseFunctions::findSummVector(point_t point, double dx, double dy)
{
  point.x += dx;
  point.y += dy;
  return point;
}

point_t baseFunctions::findDifference(point_t position, point_t rect)
{
  return {position.x - rect.x, position.y - rect.y};
}

point_t baseFunctions::makeScale(point_t point, point_t center, double k)
{
  point.x = center.x + (point.x - center.x) * k;
  point.y = center.y + (point.y - center.y) * k;
  return point;
}

double baseFunctions::findRadius(double radius, double k)
{
  return radius * k;
}

point_t baseFunctions::makeCenterMove(point_t center, point_t center_rect, double k)
{
  center.x = center_rect.x * k;
  center.y = center_rect.y * k;
  return center;
}

void baseFunctions::findCorrectKoeff(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Error: coefficient under zero");
  }
}
