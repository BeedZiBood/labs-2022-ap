#include "ellipse.h"
#include <stdexcept>

Ellipse::Ellipse(point_t pos, double r1, double r2):
  r1_(r1),
  r2_(r2),
  rect_{r2_ * 2, r1_ * 2, pos}
{
  if (r1_ <= 0 || r2_ <= 0) {
    throw std::invalid_argument("Incorrect ellipse size");
  }
}

double Ellipse::getArea() const
{
  return r1_ * r2_ * 3.14;
}

rectangle_t Ellipse::getFrameRect() const
{
  return rect_;
}

void Ellipse::move(point_t point)
{
  rect_.pos = point;
}

void Ellipse::move(double dx, double dy)
{
  addVector(rect_.pos, dx, dy);
}

void Ellipse::scale(double k)
{
  r1_ *= k;
  r2_ *= k;
  rect_.width *= k;
  rect_.height *= k;
}

Shape *Ellipse::clone()
{
  return new Ellipse(rect_.pos, r1_, r2_);
}