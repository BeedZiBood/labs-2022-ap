#include "base_types.h"
#include <cmath>
#include <stdexcept>
#include <algorithm>

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

bool isRightTriangle(point_t f_top, point_t s_top, point_t t_top)
{
  double f_side = std::pow(findModule(f_top, s_top), 2);
  double s_side = std::pow(findModule(f_top, t_top), 2);
  double t_side = std::pow(findModule(s_top, t_top), 2);
  return ((f_side + s_side == t_side) || (f_side + t_side == s_side) || (s_side + t_side == f_side));
}

bool isTriangle(point_t f_top, point_t s_top, point_t t_top)
{
  double f_side = findModule(f_top, s_top);
  double s_side = findModule(f_top, t_top);
  double t_side = findModule(s_top, t_top);
  return ((f_side + s_side > t_side) && (f_side + t_side > s_side) && (s_side + t_side > f_side));
}

bool isParallelogram(point_t f_top, point_t s_top, point_t t_top)z
{
  if (!(isTriangle(f_top, s_top, t_top)))
  {
    return isTriangle(f_top, s_top, t_top);
  }
  else
  {
    return (((f_top.y == s_top.y) || (s_top.y = t_top.y)) && (f_top.y - s_top.y != s_top.y - t_top.y));
  }
}

bool isDiamond(point_t f_top, point_t s_top, point_t t_top)
{
  if (!(isTriangle(f_top, s_top, t_top)))
  {
    return isTriangle(f_top, s_top, t_top);
  }
  else
  {
    return (((f_top.y == s_top.y) || (s_top.y = t_top.y)) && (f_top.y - s_top.y != s_top.y - t_top.y) && isRightTriangle(point_t f_top, point_t s_top, point_t t_top));
  }
}

point_t scalePoint(point_t point, point_t position, double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Error ratio");
  }
  double dx = (point.x - position.x) * k;
  double dy = (point.y - position.y) * k;
  point_t d_point{ dx, dy };
  return movePoint(position, d_point);
}

point_t getCenterDiamond(point_t f_top, point_t s_top, point_t t_top)
{
  if (f_top.x == t_top.x)
  {
    return f_top;
  }
  else if (s_top.x == t_top.x)
  {
    return s_top;
  }
}
