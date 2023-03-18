#ifndef BASETYPES_H
#define BASETYPES_H

struct point_t
{
  double x;
  double y;
};

struct rectangle_t
{
  point_t center;
  double width;
  double height;
};

rectangle_t makeNewRect(point_t leftBott, point_t rightTop);
double makeLine(point_t begin, point_t end);
point_t multVec(point_t begin, point_t end, double k);
point_t sumVec(point_t a, point_t b);

#endif
