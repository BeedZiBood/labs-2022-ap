#ifndef BASE_TYPES_H
#define BASE_TYPES_H

struct point_t {
  double x, y;
};

struct rectangle_t {
  double width, height;
  point_t pos;
};

struct vector_t {
  double x, y;
  vector_t operator*(double k) const;
};

void addVector(point_t& point, vector_t vector);
vector_t getVector(point_t p1, point_t p2);

#endif
