#include "iscale.hpp"
#include <stdexcept>

void iScaleCheck(Shape *shape, scale_t scale)
{
  if (scale.scale <= 0)
  {
    throw std::invalid_argument("Invalid scale size");
  }
  iScaleWithoutChecking(shape, scale);
}

void iScaleWithoutChecking(Shape *shape, scale_t scale)
{
  point_t pos = shape->getFrameRect().pos;
  shape->move(scale.pos);
  shape->scaleWithoutCheck(scale.scale);
  point_t delta = findDeltaScale(pos, scale);
  shape->move(delta.x, delta.y);
}
