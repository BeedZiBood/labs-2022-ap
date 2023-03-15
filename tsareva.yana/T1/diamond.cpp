#include "diamond.h"
#include <stdexcept>
#include <cmath>
#include <algorithm>

Diamond::Diamond(point_t first, point_t second, point_t third):
  first_(first),
  second_(second),
  third_(third)
{
  if (!(isDiamond(first, second, third)))
  {
    throw std::invalid_argument("Error diamond parameters");
  }
  if (second_.y == third_.y)
  {
    first_ = third;
    third_ = first;
  }
  if (first_.y == third_.y)
  {
    second_ = third;
    third_ = second;
  }
}

void Diamond::move(double dx, double dy)
{
  point_t d_point{ dx, dy };
  first_ = movePoint(first_, d_point);
  second_ = movePoint(second_, d_point);
  third_ = movePoint(third_, d_point);
}

double Diamond::getArea() const
{
  double height = std::fabs(first_.y - third_.y);
  double width = std::fabs(first_.x - second_.x);
  return  2 * height * width;
}

void Diamond::move(point_t point)
{
  point_t position = getCenterDiamond(first_, second_, third_);
  double dx = point.x - position.x;
  double dy = point.y - position.y;
  move(dx, dy);
}

void Diamond::scale(double k)
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

rectangle_t Diamond::getFrameRectangle() const
{
  double minPointX = std::min(first_.x, std::min(second_.x, third_.x));
  double maxPointX = std::max(first_.x, std::max(second_.x, third_.x));
  double minPointY = std::min(first_.y, std::min(second_.y, third_.y));
  double maxPointY = std::max(first_.y, std::max(second_.y, third_.y));
  return { 2 * (maxPointY - minPointY), 2 * (maxPointX - minPointX), getCenterDiamond(first_, second_, third_)};
}

