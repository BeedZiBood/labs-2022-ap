#include "parallelogram.h"
#include <stdexcept>
#include <cmath>

Parallelogram::Parallelogram(point_t first, point_t second, point_t third):
  first_(first),
  second_(second),
  third_(third)
{
  if (!((first_.y == second_.y) || (second_.y == third_.y)))
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

