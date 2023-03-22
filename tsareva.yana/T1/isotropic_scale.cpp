#include "isotropic_scale.h"
#include <stdexcept>

void tsareva::isotropicScale(Shape * figure, tsareva::point_t point, double k)
{
  tsareva::point_t start = figure->getFrameRectangle().position;
  figure->scale(k);
  figure->move(point);
  tsareva::point_t finish = figure->getFrameRectangle().position;
  figure->move(k * (start.x - finish.x), k * (start.y - finish.y));
}
