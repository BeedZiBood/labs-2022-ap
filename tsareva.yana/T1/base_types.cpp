#include "base_types.h"
#include <cmath>
#include <stdexcept>
#include <algorithm>

tsareva::point_t tsareva::movePoint(tsareva::point_t point, tsareva::point_t d_point)
{
  return tsareva::point_t{ point.x + d_point.x, point.y + d_point.y };
}

tsareva::point_t tsareva::getCenterParallelogram(tsareva::point_t f_top, tsareva::point_t s_top)
{
  return { (f_top.x + s_top.x) / 2, (f_top.y + s_top.y) / 2 };
}

double tsareva::findModule(tsareva::point_t f_top, tsareva::point_t s_top)
{
  return std::sqrt(std::pow(f_top.x - s_top.x, 2) + std::pow(f_top.y - s_top.y, 2));
}

bool isTriangle(tsareva::point_t f_top, tsareva::point_t s_top, tsareva::point_t t_top)
{
  double f_side = tsareva::findModule(f_top, s_top);
  double s_side = tsareva::findModule(f_top, t_top);
  double t_side = tsareva::findModule(s_top, t_top);
  return (f_side + s_side > t_side) && (f_side + t_side > s_side) && (s_side + t_side > f_side);
}

bool tsareva::isParallelogram(tsareva::point_t f_top, tsareva::point_t s_top, tsareva::point_t t_top)
{
  return isTriangle(f_top, s_top, t_top) && (f_top.y == s_top.y || s_top.y == t_top.y || f_top.y == t_top.y);
}

bool tsareva::isDiamond(tsareva::point_t f_t, tsareva::point_t s_t, tsareva::point_t t_t)
{
  return isTriangle(f_t, s_t, t_t) && ((f_t.y == s_t.y && s_t.x == t_t.x) || (s_t.y == t_t.y && f_t.x == t_t.x));
}

tsareva::point_t tsareva::scalePoint(tsareva::point_t point, tsareva::point_t position, double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Error ratio");
  }
  double dx = (point.x - position.x) * k;
  double dy = (point.y - position.y) * k;
  tsareva::point_t d_point{ dx, dy };
  return tsareva::movePoint(position, d_point);
}

tsareva::point_t tsareva::getCenterDiamond(tsareva::point_t f_top, tsareva::point_t s_top, tsareva::point_t t_top)
{
  if (f_top.x == t_top.x)
  {
    return f_top;
  }
  else if (s_top.x == t_top.x)
  {
    return s_top;
  }
  return {0, 0};
}

tsareva::point_t tsareva::getLeftDown(rectangle_t rectangle)
{
  return {rectangle.pos.x - rectangle.width / 2, rectangle.pos.y - rectangle.height / 2 };
}

tsareva::point_t tsareva::getRightUp(rectangle_t rectangle)
{
  return {rectangle.pos.x + rectangle.width / 2, rectangle.pos.y + rectangle.height / 2 };
}
