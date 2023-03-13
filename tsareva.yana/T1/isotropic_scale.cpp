#include "isotropic_scale.h"
#include <stdexcept>

void isotropicScale(Shape * figure, point_t point, double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Error ratio");
  }
  point_t start = figure->getFrameRectangle().position;
  figure->move(point);
  point_t finish = figure->getFrameRectangle().position;
  figure->scale(k);
  figure->move(k * (start.x - finish.x), k * (start.y - finish.y));
}


