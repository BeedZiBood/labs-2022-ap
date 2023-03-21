#include "ellipse.h"
#include <stdexcept>

kozyrin::Ellipse::Ellipse(point_t pos, double r1, double r2):
  r1_(r1),
  r2_(r2),
  rect_{r2_ * 2, r1_ * 2, pos}
{
  if (r1_ <= 0 || r2_ <= 0) {
    throw std::invalid_argument("Incorrect ellipse size");
  }
}

double kozyrin::Ellipse::getArea() const
{
  return r1_ * r2_ * 3.14159265359;
}

kozyrin::rectangle_t kozyrin::Ellipse::getFrameRect() const
{
  return rect_;
}

void kozyrin::Ellipse::move(point_t point)
{
  rect_.pos = point;
}

void kozyrin::Ellipse::move(double dx, double dy)
{
  addVector(rect_.pos, {dx, dy});
}

void kozyrin::Ellipse::scale(double k)
{
  r1_ *= k;
  r2_ *= k;
  rect_.width *= k;
  rect_.height *= k;
}

kozyrin::Shape* kozyrin::Ellipse::clone()
{
  return new Ellipse(rect_.pos, r1_, r2_);
}
