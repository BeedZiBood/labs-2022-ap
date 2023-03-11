#ifndef BASE_TYPES_H
#define BASE_TYPES_H
struct point_t
{
  double x;
  double y;
};

struct rectangle_t
{
  double height;
  double width;
  point_t position;
};

point_t movePoint(point_t point, point_t d_point);
point_t getCenterParallelogram(point_t f_top, point_t s_top);
bool isTriangle(point_t f_top, point_t s_top, point_t t_top);
double findModule(point_t f_top, point_t s_top);
bool isParallelogram(point_t f_top, point_t s_top, point_t t_top);
bool isDiamond(point_t f_top, point_t s_top, point_t t_top);
bool isRightTriangle(point_t f_top, point_t s_top, point_t t_top);
point_t scalePoint(point_t point, point_t position, double k);
#endif
