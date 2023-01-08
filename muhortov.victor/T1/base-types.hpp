#ifndef GITLAB_LABS_BASE_TYPES_HPP
#define GITLAB_LABS_BASE_TYPES_HPP

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

double calculatePointsDistance(const point_t &p1, const point_t &p2);
double findDeltaScale(double x, scale_t scale);
point_t calculateVectorSum(point_t position, double delta_x, double delta_y);
point_t calculateVectorDifference(point_t position, double delta_x, double delta_y);
point_t calculateScale(point_t position, point_t center, double k);
point_t moveToDelta(point_t position, double delta_x, double delta_y);
double calculateTriangleArea(const double &a, const double &b, const double &c);
double calculateSideForTriangle(const point_t &one, const point_t &two);
bool checkingSideForPosition(const point_t &one, const point_t &two, const point_t &four);
bool checkingTriangle(const point_t &one, const point_t &two, const point_t &three);
bool checkingPosition(const point_t &one, const point_t &two, const point_t &three, const point_t &four);
bool checkingConcave(const point_t &one, const point_t &two, const point_t &three, const point_t &four);

#endif
