#include "basetype.h"

chulkov::point_t chulkov::movePoint(const point_t p, const point_t dp)
{
  return point_t{p.x + dp.x, p.y + dp.y};
}
