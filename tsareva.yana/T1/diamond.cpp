#include "diamond.h"
#include <stdexcept>
#include <cmath>
#include <algorithm>

tsareva::point_t getFirstPoint(tsareva::point_t f_p, tsareva::point_t s_p, tsareva::point_t t_p)
{
  if (s_p.y == t_p.y)
  {
    return t_p;
  }
  else
  {
    return f_p;
  }
}

tsareva::point_t getSecondPoint(tsareva::point_t f_p, tsareva::point_t s_p, tsareva::point_t t_p)
{
  if (f_p.y == t_p.y)
  {
    return t_p;
  }
  return s_p;
}

tsareva::point_t getThirdPoint(tsareva::point_t f_p, tsareva::point_t s_p, tsareva::point_t t_p)
{
  if (s_p.y == t_p.y)
  {
    return f_p;
  }
  if (f_p.y == t_p.y)
  {
    return s_p;
  }
  return t_p;
}

tsareva::Diamond::Diamond(tsareva::point_t first, tsareva::point_t second, tsareva::point_t third):
  first_(getFirstPoint(first, second, third)),
  second_(getSecondPoint(first, second, third)),
  third_(getThirdPoint(first, second, third))
{
  if (!(isDiamond(first, second, third)))
  {
    throw std::invalid_argument("Error diamond parameters");
  }
}

void tsareva::Diamond::move(double dx, double dy)
{
  tsareva::point_t d_point{ dx, dy };
  first_ = movePoint(first_, d_point);
  second_ = movePoint(second_, d_point);
  third_ = movePoint(third_, d_point);
}

double tsareva::Diamond::getArea() const
{
  double height = std::fabs(first_.y - third_.y);
  double width = std::fabs(first_.x - second_.x);
  return  2 * height * width;
}

void tsareva::Diamond::move(tsareva::point_t point)
{
  point_t position = getCenterDiamond(first_, second_, third_);
  double dx = point.x - position.x;
  double dy = point.y - position.y;
  move(dx, dy);
}

void tsareva::Diamond::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Error ratio");
  }
  point_t position = getCenterDiamond(first_, second_, third_);
  first_ = scalePoint(first_, position, k);
  second_= scalePoint(second_, position, k);
  third_ = scalePoint(third_, position, k);
}

tsareva::rectangle_t tsareva::Diamond::getFrameRectangle() const
{
  double minPointX = std::min(first_.x, std::min(second_.x, third_.x));
  double maxPointX = std::max(first_.x, std::max(second_.x, third_.x));
  double minPointY = std::min(first_.y, std::min(second_.y, third_.y));
  double maxPointY = std::max(first_.y, std::max(second_.y, third_.y));
  return { 2 * (maxPointY - minPointY), 2 * (maxPointX - minPointX), getCenterDiamond(first_, second_, third_)};
}

