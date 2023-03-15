#ifndef BASE_TYPES_H
#define BASE_TYPES_H
#include <cmath>
#include <stdexcept>

struct point_t
{
  double x;
  double y;
};

struct rectangle_t
{
  double width;
  double height;
  point_t pos;
};

point_t getCenterRectangle(const point_t& l_point, const point_t& r_point);
bool isCorrectRectangle(const point_t& ld_point, const point_t& ru_point);
point_t scalePoint(const point_t& point, const point_t& pos, double k);
point_t getCenterParallelogram(const point_t& lu_point, const point_t& rd_point);
point_t movePoint(const point_t& point, const point_t& dpoint);
bool isCorrectParallelogram(const point_t& A, const point_t& B, const point_t& C);
bool isCorrectTriangle(const point_t& A, const point_t& B, const point_t& C);
point_t getCenterTriangle(const point_t& A, const point_t& B, const point_t& C);
double getSide(const point_t& p1, const point_t& p2);

#endif
