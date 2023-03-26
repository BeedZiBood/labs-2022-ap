#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

struct point_t
{
  double x, y;
};

struct rectangle_t
{
  point_t pos;
  double width, height;
};

struct scale_t
{
  point_t pos;
  double scale;
};

double calcVectorLength(const point_t &p1, const point_t &p2);
bool validateConcave(point_t dots[]);
point_t addVector(point_t dot, double dx, double dy);
bool checkTriangles(point_t dots[]);
point_t scaleDelta(point_t pos, scale_t scale);
bool validateTriangle(point_t a, point_t b, point_t c);
point_t getVectorDiff(point_t position, point_t delta);

#endif
