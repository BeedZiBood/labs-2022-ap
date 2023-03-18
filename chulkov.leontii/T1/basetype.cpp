#include "basetype.h"

point_t movePoint(const point_t p, const point_t dp)
{
  return point_t{p.x + dp.x, p.y + dp.y};
}
