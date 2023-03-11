#include "base_types.h"
#include <cmath>

point_t movePoint(point_t point, point_t d_point)
{
  return point_t{ point.x + d_point.x, point.y + d_point.y };
}

point_t getCenterParallelogram(point_t f_top, point_t s_top)
{
  return { (f_top.x + s_top.x) / 2, (f_top.y + s_top.y) / 2 };
}

double findModule(point_t f_top, point_t s_top)
{
  return std::sqrt(std::pow(f_top.x - s_top.x, 2) + std::pow(f_top.y - s_top.y, 2));
}

bool isTriangle(point_t f_top, point_t s_top, point_t t_top)
{
  double first_side = findModule(f_top, s_top);
  double second_side = findModule(f_top, t_top);
  double third_side = findModule(s_top, t_top);
  if ((first_side + second_side > third_side) && (first_side + third_side > second_side) && (second_side + third_side > first_side))
  {
    return true;
  }
  return false;
}

bool isParallelogram(point_t f_top, point_t s_top, point_t t_top)
{
  if (!(isTriangle(f_top, s_top, t_top)))
  {
    return false;
  }
  else
  {
    return ((f_top.y == s_top.y) || (s_top.y = t_top.y)) && ()
  }
}

