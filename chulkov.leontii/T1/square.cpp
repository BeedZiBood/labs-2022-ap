#include "square.h"
#include <stdexcept>

chulkov::Square::Square(const point_t& pos, double side):
  rect_(pos, {pos.x + side, pos.y + side})
{
  if (side <= 0.0)
  {
    throw std::invalid_argument("Invalid side value");
  }
}

double chulkov::Square::getArea() const
{
  return rect_.getArea();
}

chulkov::rectangle_t chulkov::Square::getFrameRect() const
{
  return rect_.getFrameRect();
}

void chulkov::Square::move(const point_t& pos)
{
  rect_.move(pos);
}

void chulkov::Square::move(double dx, double dy)
{
  rect_.move(dx, dy);
}

void chulkov::Square::unsafeScale(double k)
{
  rect_.unsafeScale(k);
}

chulkov::Shape* chulkov::Square::clone() const
{
  return new Square(*this);
}
