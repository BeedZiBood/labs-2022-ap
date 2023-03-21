#include "square.h"
#include <stdexcept>

kryuchkova::Square::Square(const point_t &lb_point, const double length):
  square_(Rectangle{lb_point, point_t{lb_point.x + length, lb_point.y + length}})
{
  if (length <= 0)
  {
    throw std::invalid_argument("It's not a Square");
  }
}

kryuchkova::Square::Square(const Rectangle &rectangle):
  square_(rectangle)
{}

std::string kryuchkova::Square::getName() const
{
  return "SQUARE";
}

double kryuchkova::Square::getArea() const
{
  return square_.getArea();
}

kryuchkova::rectangle_t kryuchkova::Square::getFrameRect() const
{
  return square_.getFrameRect();
}

void kryuchkova::Square::move(const double dx, const double dy)
{
  square_.move(dx, dy);
}

void kryuchkova::Square::move(const point_t point)
{
  square_.move(point);
}

void kryuchkova::Square::unsafeScale(const double k)
{
  square_.unsafeScale(k);
}

kryuchkova::Shape *kryuchkova::Square::clone() const
{
  return new Square(square_);
}
