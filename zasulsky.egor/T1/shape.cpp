#include "shape.hpp"
#include <stdexcept>
void zasulsky::Shape::scale(double k)
{
  if (k <= 0.0)
  {
    throw std::invalid_argument("k must not be less than zero");
  }
  unsafeScale(k);
}
void zasulsky::isoScale(Shape* shp, const point_t& center, double k)
{
  if (k <= 0.0)
  {
    throw std::invalid_argument("k must not be less than zero");
  }
  unsafeIsoScale(k);
}
void zasulsky::unsafeIsoScale(Shape* shp, const point_t& center, double k)
{
  point_t A1 = shp->getFrameRect().pos;
  shp->move(center);
  point_t A2 = shp->getFrameRect().pos;
  shp->unsafeScale(k);
  unsafeIsoScalePoint(A1, center, k);
  unsafeIsoScalePoint(A2, center, k);
  shp->move(A1.x - A2.x, A1.y - A2.y);
}
