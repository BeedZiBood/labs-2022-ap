#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace chemodurov
{
  struct point_t
  {
    double x, y;
  };
  point_t operator+(const point_t & left, const point_t & right);
  point_t operator-(const point_t & left, const point_t & right);
  point_t operator*(const point_t & left, double k);
  bool operator==(const point_t & left, const point_t & right);

  struct rectangle_t
  {
    point_t pos;
    double width, height;
  };
}

#endif
