#include "base-types.h"

void kozyrin::addVector(point_t& point, vector_t vector)
{
  point.x += vector.x;
  point.y += vector.y;
}

kozyrin::vector_t kozyrin::getVector(point_t p1, point_t p2)
{
  return {p2.x - p1.x, p2.y - p1.y};
}

kozyrin::vector_t kozyrin::vector_t::operator*(double k) const
{
   return {x * k, y * k};
}
