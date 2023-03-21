#include "rectangle.hpp"
#include <stdexcept>

namespace chemodurov
{
  point_t * makeArrayOfXPoints(const point_t & left_down, const point_t & right_up)
  {
    const size_t x = 4;
    point_t * arr = new point_t[x];
    arr[0] = left_down;
    arr[1] = {left_down.x, right_up.y};
    arr[2] = right_up;
    arr[3] = {right_up.x, left_down.y};
    return arr;
  }
}

chemodurov::Rectangle::Rectangle(const point_t & left_down, const point_t & right_up):
 p(makeArrayOfXPoints(left_down, right_up), 4ull)
{
  if (left_down.x >= right_up.x || left_down.y >= right_up.y)
  {
    throw std::invalid_argument("This is not a rectangle");
  }
}
double chemodurov::Rectangle::getArea() const
{
  return p.getArea();
}
chemodurov::rectangle_t chemodurov::Rectangle::getFrameRect() const
{
  return p.getFrameRect();
}
void chemodurov::Rectangle::move(const point_t & pos)
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
chemodurov::Shape * chemodurov::Rectangle::clone() const
{
  return new Rectangle(p);
}
chemodurov::Rectangle::Rectangle(const chemodurov::Polygon & p):
 p(p)
{}
