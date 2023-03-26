#include "ring.h"
#include <stdexcept>
#include "ellipse.h"
Ring::Ring(point_t center, double radius_small, double radius_big):
  smallEllipse_(center, radius_small, radius_small),
  bigEllipse_(center, radius_big, radius_big)
{
  if (radius_big <= radius_small || radius_big <= 0 || radius_small <= 0)
  {
    throw std::invalid_argument("Error: false ring parameters");
  }
}

double Ring::getArea() const
{
  return (bigEllipse_.getArea() - smallEllipse_.getArea());
}

rectangle_t Ring::getFrameRectangle() const
{
  return bigEllipse_.getFrameRectangle();
}

void Ring::move(double dx, double dy)
{
  bigEllipse_.move(dx, dy);
}

void Ring::move(point_t position)
{
  bigEllipse_.move(position);
}

void Ring::scale(double k)
{
  bigEllipse_.scale(k);
  smallEllipse_.scale(k);
}
