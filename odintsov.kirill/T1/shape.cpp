#include "shape.hpp"
#include "base-types.hpp"

void odintsov::isoScale(Shape* shp, const point_t& anchor, double k)
{
  point_t A1 = shp->getFrameRect().pos;
  shp->move(anchor);
  point_t A2 = shp->getFrameRect().pos;
  shp->scale(k);
  isoScalePoint(A1, anchor, k);
  isoScalePoint(A2, anchor, k);
  shp->move(A1.x - A2.x, A1.y - A2.y);
}
