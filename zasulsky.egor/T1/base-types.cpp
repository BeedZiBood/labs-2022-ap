#include "base-types.hpp"
#include <stdexcept>
#include "shape.hpp"

void zasulsky::movePoint(point_t& p, double dx, double dy)
{
  p.x += dx;
  p.y += dy;
}
void zasulsky::isoScalePoint(point_t& p, const point_t& center, double k)
{
  if (k <= 0.0)
  {
    throw std::invalid_argument("k must not be less than zero");
  }
  unsafeIsoScalePoint(p, center, k);
}
void unsafeIsoScalePoint(point_t& p, const point_t& center, double k)
{
  movePoint(p, (p.x - center.x) * (k - 1.0), (p.y - center.y) * (k - 1.0));
}
zasulsky::rectangle_t zasulsky::getFrameRectFromCorners(const point_t& bl, const point_t& tr)
{
  if (tr.x < bl.x || tr.y < bl.y)
  {
    throw std::invalid_argument("corners set incorrectly");
  }
  return rectangle_t{ tr.x - bl.x, tr.y - bl.y, {(bl.x + tr.x) * 0.5, (bl.y + tr.y) * 0.5} };
}
