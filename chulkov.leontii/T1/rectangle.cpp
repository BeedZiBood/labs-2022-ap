#include "rectangle.h"
#include <stdexcept>
#include <cmath>

chulkov::Rectangle::Rectangle(point_t width, point_t height):
  rect_{ {width.x + (height.x - width.x) / 2, width.y + (height.y - width.y) / 2},
        std::fabs(height.x - width.x), std::fabs(height.y - width.y) }
{
  if (rect_.width_ < 0.0 || rect_.height_ < 0.0)
  {
    throw std::invalid_argument("Error: Invalid rectangle dimensions");
  }
}

double chulkov::Rectangle::getArea() const
{
  return rect_.width_ * rect_.height_;
}

chulkov::rectangle_t chulkov::Rectangle::getFrameRect() const
{
  return rect_;
}

void chulkov::Rectangle::move(const double dx, const double dy)
{
  rect_.pos_ = movePoint(rect_.pos_, point_t{dx, dy});
}

void chulkov::Rectangle::move(const point_t& pos)
{
  rect_.pos_ = pos;
}

void chulkov::Rectangle::unsafeScale(double k)
{
  rect_.width_ *= k;
  rect_.height_ *= k;
}

chulkov::Shape* chulkov::Rectangle::clone() const
{
  return new Rectangle(*this);
}
