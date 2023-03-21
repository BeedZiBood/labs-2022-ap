#include "parallelogram.hpp"
#include <stdexcept>
#include "is-repeating-points-in-array.hpp"

namespace chemodurov
{
  point_t * makeArray(const point_t & fst, const point_t & sec, const point_t & trd)
  {
    const size_t x = 4;
    point_t * arr = new point_t[x];
    arr[0] = fst;
    arr[1] = sec;
    arr[2] = trd;
    arr[3] = {fst.x - sec.x + trd.x, fst.y - sec.y + trd.y};
    if (isRepeatingPointsInArray(arr, x))
    {
      delete [] arr;
      throw std::invalid_argument("Not correct vertices of polygon");
    }
    return arr;
  }
}
chemodurov::Parallelogram::Parallelogram(const point_t & fst, const point_t & sec, const point_t & trd):
 p(makeArray(fst, sec, trd), 4ull)
{
  if ((fst.y != sec.y && sec.y != trd.y) || fst == sec || sec == trd)
  {
    throw std::invalid_argument("Not correct parameters");
  }
}
double chemodurov::Parallelogram::getArea() const
{
  return p.getArea();
}
chemodurov::rectangle_t chemodurov::Parallelogram::getFrameRect() const
{
  return p.getFrameRect();
}
void chemodurov::Parallelogram::move(const point_t & pos)
{
  p.move(pos);
}
void chemodurov::Parallelogram::move(double dx, double dy)
{
  p.move(dx, dy);
}
void chemodurov::Parallelogram::scale(double k)
{
  p.scale(k);
}
chemodurov::Parallelogram::Parallelogram(const Polygon & pol):
 p(pol)
{}
chemodurov::Shape * chemodurov::Parallelogram::clone() const
{
  return new Parallelogram(p);
}
