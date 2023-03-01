#include "shape.hpp"
#include <stdexcept>
void zasulsky::isoScale(Shape* shp, const point_t& center, double k)
{
  if (k <= 0.0)
  {
    throw std::invalid_argument("k must not be less than zero");
  }
  point_t A1 = shp->getFrameRect().pos;
  shp->move(center);
  point_t A2 = shp->getFrameRect().pos;
  shp->scale(k);
  isoScalePoint(A1, center, k);
  isoScalePoint(A2, center, k);
  shp->move(A1.x - A2.x, A1.y - A2.y);
}
