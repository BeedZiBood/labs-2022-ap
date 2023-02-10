#include "base-types.h"
#include <cmath>

rectangle_t makeNewRect(point_t leftBott, point_t rightTop)
{
  double width = rightTop.x - leftBott.x;
  double height = rightTop.y - leftBott.y;
  point_t center{ leftBott.x + width / 2, leftBott.y + height / 2 };

  return rectangle_t{ center, width, height };
}

double makeLine(point_t begin, point_t end)
{
  return std::sqrt((end.x - begin.x) * (end.x - begin.x) + (end.y - begin.y) * (end.y - begin.y));
}

point_t multVec(point_t begin, point_t end, double k)
{
  return point_t{ begin.x + (end.x - begin.x) * k,  begin.y + (end.y - begin.y) * k };
}
