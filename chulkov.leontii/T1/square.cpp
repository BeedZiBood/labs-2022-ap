#include "square.h"
#include <stdexcept>

Square::Square(const point_t& pos, double side):
  rect_(Rectangle{pos, point_t {pos.x + side, pos.y + side}})
{
  if (side <= 0.0)
  {
    throw std::invalid_argument("Invalid side value");
  }
}

double Square::getArea() const
{
  return rect_.getArea();
}

rectangle_t Square::getFrameRect() const
{
  return rect_.getFrameRect();
}

void Square::move(const point_t& pos)
{
  rect_.move(pos);
}

void Square::move(double dx, double dy)
{
  rect_.move(dx, dy);
}

void Square::scale(double k)
{
  if (k <= 0.0)
  {
    throw std::invalid_argument("Invalid scale");
  }
  rect_.scale(k);
}
Shape* Square::clone() const
{
  return new Square(*this);
}
