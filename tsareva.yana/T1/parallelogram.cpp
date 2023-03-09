#include "parallelogram.h"
#include <stdexcept>
#include <cmath>
#include <algorithm>

Parallelogram::Parallelogram(point_t first, point_t second, point_t third):
  first_(first),
  second_(second),
  third_(third)
{
  if (!((first_.y == second_.y) || (second_.y == third_.y)) && (first_.y - second_.y != third_.y - second_.y))
  {
    throw std::invalid_argument("Error parallelogram parameters");
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

void Parallelogram::move(double dx, double dy)
{
  point_t d_point{ dx, dy };
  first_ = movePoint(first_, d_point);
  second_ = movePoint(second_, d_point);
  third_ = movePoint(third_, d_point);
}

double Parallelogram::getArea() const
{
  double height = std::fabs(first_.y - third_.y);
  double width = std::fabs(first_.x - second_.x);
  return height * width;
}

rectangle_t Parallelogram::getFrameRectangle() const
{
  double minPointX = std::min(first_.x, std::min(second_.x, third_.x));
  double maxPointX = std::max(first_.x, std::max(second_.x, third_.x));
  double minPointY = std::min(first_.y, std::min(second_.y, third_.y));
  double maxPointY = std::max(first_.y, std::max(second_.y, third_.y));
  return { maxPointX - minPointX, maxPointY - minPointY, getCenterParallelogram(first_, third_)};
}

void Parallelogram::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Error ratio");
  }
}

void Parallelogram::move(point_t point)
{
  point_t position = getCenterParallelogram(first_, third_);
  double dx = point.x - position.x;
  double dy = point.y - position.y;
  move(dx, dy);
}
