#include "circle.h"
#include <stdexcept>

kryuchkova::Circle::Circle(const point_t &pos, const double radius):
  pos_(pos),
  radius_(radius)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("It's not a Circle");
  }
}

std::string kryuchkova::Circle::getName() const
{
  return "CIRCLE";
}

double kryuchkova::Circle::getArea() const
{
  double pi = 3.14159265358979323846;
  return pi * radius_ * radius_;
}

kryuchkova::rectangle_t kryuchkova::Circle::getFrameRect() const
{
  return rectangle_t{radius_ * 2, radius_ * 2, pos_};
}

void kryuchkova::Circle::move(double dx, double dy)
{
  pos_ = movePoint(pos_, point_t{dx, dy});
}

void kryuchkova::Circle::move(point_t point)
{
  pos_ = point;
}

void kryuchkova::Circle::unsafeScale(const double k)
{
  radius_ *= k;
}

kryuchkova::Shape *kryuchkova::Circle::clone() const
{
  return new Circle(pos_, radius_);
}
