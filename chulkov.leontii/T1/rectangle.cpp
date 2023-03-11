#include "rectangle.h"
#include <stdexcept>

Rectangle::Rectangle(point_t width, point_t height):
  rect_(rectangle_t())
{
  rect_.width_ = height.x - width.x;
  rect_.height_ = height.y - width.y;
  rect_.pos_ = {width.x + rect_.width_ / 2, width.y + rect_.height_ / 2};
  if (rect_.width_ < 0.0 || rect_.height_ < 0.0)
  {
    throw std::invalid_argument("Error: Invalid rectangle dimensions");
  }
}

double Rectangle::getArea() const
{
  return rect_.width_ * rect_.height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rect_;
}

void Rectangle::move(const double dx, const double dy)
{
  rect_.pos_.x += dx;
  rect_.pos_.y += dy;
}

void Rectangle::move(const point_t& pos)
{
  rect_.pos_ = pos;
}

void Rectangle::scale(double k)
{
  if (k < 0.0)
  {
    throw std::invalid_argument("Error: Invalid scale");
  }
  rect_.width_ *= k;
  rect_.height_ *= k;
}

Shape* Rectangle::clone() const
{
  return new Rectangle(*this);
}
