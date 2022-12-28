#include "rectangle.hpp"
#include <stdexcept>

namespace chemodurov
{
  chemodurov::point_t * makeArrayOfXPoints(const chemodurov::point_t & left_down, const chemodurov::point_t & right_up)
  {
    const size_t x = 4;
    chemodurov::point_t * arr = new chemodurov::point_t[x];
    arr[0] = left_down;
    arr[1] = {left_down.x, right_up.y};
    arr[2] = right_up;
    arr[3] = {right_up.x, left_down.y};
    return arr;
  }
}

chemodurov::Rectangle::Rectangle(const chemodurov::point_t & left_down, const chemodurov::point_t & right_up):
 p(makeArrayOfXPoints(left_down, right_up), 4ull)
{
  if (left_down.x == right_up.x || left_down.y == right_up.y)
  {
    throw std::invalid_argument("This is not a rectangle");
  }
}
chemodurov::Rectangle::~Rectangle()
{}
double chemodurov::Rectangle::getArea() const
{
  return p.getArea();
}
chemodurov::rectangle_t chemodurov::Rectangle::getFrameRect() const
{
  return p.getFrameRect();
}
void chemodurov::Rectangle::move(const chemodurov::point_t & pos)
{
  p.move(pos);
}
void chemodurov::Rectangle::move(double dx, double dy)
{
  p.move(dx, dy);
}
void chemodurov::Rectangle::scale(double k)
{
  p.scale(k);
}
