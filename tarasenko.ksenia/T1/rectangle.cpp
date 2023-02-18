#include "rectangle.hpp"
#include <stdexcept>
#include "base-func.hpp"

tarasenko::Rectangle::Rectangle(point_t point_ld, point_t point_ru):
  rect_(makeRectangle(point_ld, point_ru))
{}

tarasenko::Rectangle::Rectangle(rectangle_t rect):
  rect_(rect)
{}

double tarasenko::Rectangle::getArea() const
{
  return rect_.width_ * rect_.height_;
}

tarasenko::rectangle_t tarasenko::Rectangle::getFrameRect() const
{
  return rect_;
}

void tarasenko::Rectangle::move(point_t pos)
{
  rect_.pos_ = pos;
}

void tarasenko::Rectangle::move(double dx, double dy)
{
  rect_.pos_ = rect_.pos_ + point_t{dx, dy};
}

void tarasenko::Rectangle::scale(double k)
{
  this->checkCoefficient(k);
  rect_.width_ *= k;
  rect_.height_ *= k;
}

tarasenko::Shape * tarasenko::Rectangle::clone() const
{
  return new Rectangle(rect_);
}
