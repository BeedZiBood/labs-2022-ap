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
point_t getCenterParallelogram(point_t first_top, point_t second_top);
bool isTriangle(point_t first_top, point_t second_top, point_t third_top);
double findModule(point_t first_top, point_t second_top);
#endif
