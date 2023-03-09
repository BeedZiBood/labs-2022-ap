#include "base_types.h"

point_t movePoint(point_t point, point_t d_point)
{
  return point_t{ point.x + d_point.x, point.y + d_point.y };
}

point_t getCenterParallelogram(point_t first_top, point_t second_top)
{
  return { (first_top.x + second_top.x) / 2, (first_top.y + second_top.y) / 2 };
}
