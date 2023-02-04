#include "base-types.h"

rectangle_t makeNewRect(point_t leftBott, point_t rightTop)
{
  double wedth = rightTop.x - leftBott.x;
  double height = rightTop.y - leftBott.y;

  point_t pos{ (wedth / 2) + leftBott.x, (height / 2) + leftBott.y };

  rectangle_t newRec{ pos, wedth, height };

  return newRec;
}

point_t shiftPoint(point_t source, double x, double y)
{
  source.x = source.x + x;
  source.y = source.y + y;

  return source;
}

point_t multVec(point_t begin, point_t end, double k)
{
  end.x = (end.x - begin.x) * k;
  end.y = (end.y - begin.y) * k;

  return end;
}
