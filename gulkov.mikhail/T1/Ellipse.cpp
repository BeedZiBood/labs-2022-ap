#include "Ellipse.hpp"
#include <stdexcept>

Ellipse::Ellipse(point_t one, double r1, double r2):
  rect_({{one.x, one.y}, r2 * 2.0, r1 * 2.0}),
  r1_(r1),
  r2_(r2)
{
  if (r1 <= 0.0 || r2 <= 0.0)
  {
    throw std::invalid_argument("bad ellipse size");
  }
}

double Ellipse::getArea() const
{
  return r1_ * r2_ * 3.14159265358979323846;
}

rectangle_t Ellipse::getFrameRect() const
{
  return rect_;
}

void Ellipse::move(double dx, double dy)
{
  rect_.pos = addVector(rect_.pos, dx, dy);
}

void Ellipse::move(point_t position)
{
  rect_.pos = position;
}

void Ellipse::makeScale(double k)
{
  r1_ = r1_ * k;
  r2_ = r2_ * k;
  rect_.width = r2_ * 2.0;
  rect_.height = r1_ * 2.0;
}

Shape *Ellipse::clone() const
{
  return new Ellipse(rect_.pos, r1_, r2_);
}
