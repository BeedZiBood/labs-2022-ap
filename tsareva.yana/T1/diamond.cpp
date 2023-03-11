#include "diamond.h"
#include <stdexcept>
#include <cmath>

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
  point_t position = getCenterParallelogram(first_, third_);
  double dx = point.x - position.x;
  double dy = point.y - position.y;
  move(dx, dy);
}
