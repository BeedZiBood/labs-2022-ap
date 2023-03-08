#include "rectangle.h"
#include <stdexcept>

Rectangle::Rectangle(const double width, const double height, const point_t& pos):
  width_(width),
  height_(height),
  pos_(pos)
{
  if (width_ < 0.0 || height_ < 0.0)
  {
    throw std::invalid_argument("Error: Invalid rectangle dimensions");
  }
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {pos_, width_, height_};
}