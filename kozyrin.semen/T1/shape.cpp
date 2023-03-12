#include "shape.h"

void isoScale(Shape* shp, point_t point, double k)
{
  point_t pos1 = shp->getFrameRect().pos;
  shp->move(point);
  point_t pos2 = shp->getFrameRect().pos;
  shp->scale(k);
  vector_t vector = getVector(pos2, pos1) * k;
  shp->move(vector.x, vector.y);
}
