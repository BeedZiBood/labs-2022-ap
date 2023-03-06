#include "base_functions.h"

point_t baseFunctions::findMove(point_t point, double dx, double dy)
{
  point.x += dx;
  point.y += dy;
  return point;
}
