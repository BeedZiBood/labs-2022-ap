#include "diamond.hpp"
#include <stdexcept>
#include "rectangle.hpp"

Diamond::Diamond(point_t one, point_t two, point_t three):
  rectangle(findLastDiamondPosition(one, two, three))
{}

double Diamond::getArea() const
{
  return 0.5 * rectangle.getArea();
}

rectangle_t Diamond::getFrameRect() const
{
  return rectangle.getFrameRect();
}

void Diamond::move(point_t position)
{
  rectangle.move(position);
}

void Diamond::move(double delta_x, double delta_y)
{
  rectangle.move(delta_x, delta_y);
}

void Diamond::scaleWithoutCheck(double k)
{
  rectangle.scaleWithoutCheck(k);
}

Shape *Diamond::clone() const
{
  return new Diamond(*this);
}

Rectangle Diamond::findLastDiamondPosition(point_t one, point_t two, point_t three)
{
  if (one.x == two.x && one.y == three.y)
  {
    return {{three.x, calcPosXY(two, one).y}, {calcPosXY(three, one).x, two.y}};
  }
  else if (one.y == two.y && one.x == three.x)
  {
    return {{two.x, calcPosXY(three, one).y}, {calcPosXY(two, one).x, three.y}};
  }
  else if (two.x == one.x && two.y == three.y)
  {
    return {{three.x, calcPosXY(one, two).y}, {calcPosXY(three, two).x, one.y}};
  }
  else if (two.y == one.y && two.x == three.x)
  {
    return {{one.x, calcPosXY(three, two).y}, {calcPosXY(one, two).x, three.y}};
  }
  else if (three.x == one.x && three.y == two.y)
  {
    return {{two.x, calcPosXY(one, three).y}, {calcPosXY(two, three).x, one.y}};
  }
  else if (three.y == one.y && three.x == two.x)
  {
    return {{one.x, calcPosXY(two, three).y}, {calcPosXY(one, three).x, two.y}};
  }
  else
  {
    throw std::invalid_argument("Invalid value for DIAMOND");
  }
}
