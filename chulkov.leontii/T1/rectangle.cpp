#include "rectangle.h"
#include <stdexcept>


Rectangle::Rectangle(point_t width, point_t height):
  pos_(point_t()),
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

void Rectangle::move(const point_t& pos)
{
  pos_ = pos;
}

void Rectangle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Rectangle::scale(double k)
{
  if (k < 0.0)
  {
    throw std::invalid_argument("Error: Invalid scale");
  }
  if (k != 1.0)
  {
    rect_.width_ *= k;
    rect_.height_ *= k;
  }
}

Shape* Rectangle::clone() const
{
  return new Rectangle(*this);
}
