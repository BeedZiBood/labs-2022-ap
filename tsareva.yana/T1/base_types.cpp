#include "base_types.h"
#include <cmath>

point_t movePoint(point_t point, point_t d_point)
{
  return point_t{ point.x + d_point.x, point.y + d_point.y };
}

point_t getCenterParallelogram(point_t first_top, point_t second_top)
{
  return { (first_top.x + second_top.x) / 2, (first_top.y + second_top.y) / 2 };
}

double findModule(point_t first_top, point_t second_top)
{
  return std::sqrt(std::pow(first_top.x - second_top.x, 2) + std::pow(first_top.y - second_top.y, 2));
}

bool isTriangle(point_t first_top, point_t second_top, point_t third_top)
{
  double first_side = findModule(first_top, second_top);
  double second_side = findModule(first_top, third_top);
  double third_side = findModule(second_top, third_top);
  if ((first_side + second_side > third_side) && (first_side + third_side > second_side) && (second_side + third_side > first_side))
  {
    return true;
  }
  return false;
}

