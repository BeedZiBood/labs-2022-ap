#include "IsoScale.hpp"
#include <stdexcept>

void doSafeIsoScale(Shape *shape, scale_t scale)
{
  scale.scale <= 0.0 ? throw std::invalid_argument("Bad input, invalid scale value") : doIsoScale(shape, scale);
}

void doIsoScale(Shape *shape, scale_t scale)
{
  point_t pos = shape->getFrameRect().pos;
  shape->makeScale(scale.scale);
  shape->move(scale.pos);
  point_t offset = scaleDelta(pos, scale);
  shape->move(offset.x, offset.y);
}
