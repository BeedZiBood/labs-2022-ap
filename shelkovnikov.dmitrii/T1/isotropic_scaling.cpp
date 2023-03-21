#include "isotropic_scaling.h"
#include <stdexcept>
void dimkashelk::isotropicScaling(Shape *shape, point_t point, double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Coefficient below zero");
  }
  unsafeIsotropicScaling(shape, point, k);
}
void dimkashelk::unsafeIsotropicScaling(Shape *shape, point_t point, double k)
{
  point_t point_1 = shape->getFrameRect().pos;
  shape->move(point);
  point_t point_2 = shape->getFrameRect().pos;
  shape->unsafeScale(k);
  shape->move(-k * (point_2.x - point_1.x), -k * (point_2.y - point_1.y));
}
