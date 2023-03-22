#include "isotropic_scale.h"
#include <stdexcept>

void tsareva::isotropicScale(Shape * figure, tsareva::point_t point, double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Error ratio");
  }
  tsareva::point_t start = figure->getFrameRectangle().position;
  figure->move(point);
  tsareva::point_t finish = figure->getFrameRectangle().position;
  figure->scale(k);
  figure->move(k * (start.x - finish.x), k * (start.y - finish.y));
}


