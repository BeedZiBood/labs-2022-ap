#include "square.hpp"
#include <stdexcept>

namespace chemodurov
{
  point_t * makeArrayOfXPoints(const point_t & left_down, double length)
  {
    if (length <= 0)
    {
      throw std::invalid_argument("Not correct length of side of square");
    }
    const size_t x = 4;
    point_t * arr = new point_t[x];
    arr[0] = left_down;
    arr[1] = {left_down.x, left_down.y + length};
    arr[2] = {left_down.x + length, left_down.y + length};
    arr[3] = {left_down.x + length, left_down.y};
    return arr;
  }
}

chemodurov::Square::Square(const point_t & left_down, double length):
 p(makeArrayOfXPoints(left_down, length), 4ull)
{
  if (length <= 0)
  {
    throw std::invalid_argument("Not correct length of side of square");
  }
}
double chemodurov::Square::getArea() const
{
  return p.getArea();
}
chemodurov::rectangle_t chemodurov::Square::getFrameRect() const
{
  return p.getFrameRect();
}
void chemodurov::Square::move(const point_t & pos)
{
  p.move(pos);
}
void chemodurov::Square::move(double dx, double dy)
{
  p.move(dx, dy);
}
void chemodurov::Square::scale(double k)
{
  p.scale(k);
}
chemodurov::Shape * chemodurov::Square::clone() const
{
  return new Square(p);
}
chemodurov::Square::Square(const chemodurov::Polygon & p):
 p(p)
{}
