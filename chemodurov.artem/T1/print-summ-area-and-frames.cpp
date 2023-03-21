#include "print-summ-area-and-frames.hpp"
#include <iostream>
#include <iomanip>

namespace chemodurov
{
  void printLeftDownAndRightUp(std::ostream & out, const rectangle_t & rect)
  {
    point_t left_down{rect.pos.x - 0.5 * rect.width, rect.pos.y - 0.5 * rect.height};
    point_t right_up{rect.pos.x + 0.5 * rect.width, rect.pos.y + 0.5 * rect.height};
    out << left_down.x << ' ' << left_down.y << ' ';
    out << right_up.x << ' ' << right_up.y;
  }
}

void chemodurov::printSummAreaAndFrames(std::ostream & out, const CompositeShape & comp, size_t shp_size)
{
  if (!shp_size)
  {
    throw std::invalid_argument("Invalid size of Shape array");
  }
  double summ_area = 0.0;
  for (size_t i = 0; i < shp_size; ++i)
  {
    summ_area += comp[i]->getArea();
  }
  out << summ_area;
  for (size_t i = 0; i < shp_size; ++i)
  {
    chemodurov::printLeftDownAndRightUp(out << ' ', comp[i]->getFrameRect());
  }
}
