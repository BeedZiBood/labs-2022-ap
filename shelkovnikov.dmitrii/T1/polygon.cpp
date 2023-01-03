#include "polygon.h"
#include <algorithm>
#include "triangulatepoints.h"
#include "isotropic_scaling.h"
#include "base_functions.h"
#include "make_triangles.h"
dimkashelk::Polygon::Polygon(point_t *points, size_t size):
  count_(0),
  triangles_(makeTriangles(points, size)),
  center_{0.0, 0.0}
{
  if (size >= 3)
  {
    count_ = size - 2;
  }
  double x_sum = 0.0;
  double y_sum = 0.0;
  for (size_t i = 0; i < size; i++)
  {
    x_sum += points[i].x;
    y_sum += points[i].y;
  }
  center_ = point_t{x_sum / size, y_sum / size};
}
dimkashelk::Polygon::Polygon(const Polygon &polygon):
  count_(polygon.count_),
  triangles_(new Triangle[polygon.count_]),
  center_(polygon.center_)
{
  for (size_t i = 0; i < polygon.count_; i++)
  {
    triangles_[i] = Triangle(polygon.triangles_[i]);
  }
}
dimkashelk::Polygon::~Polygon() noexcept
{
  delete[] triangles_;
}
double dimkashelk::Polygon::getArea() const
{
  double global_area = 0.0;
  for (size_t i = 0; i < count_; i++)
  {
    global_area += triangles_[i].getArea();
  }
  return global_area;
}
dimkashelk::rectangle_t dimkashelk::Polygon::getFrameRect() const
{
  rectangle_t rectangle = triangles_[0].getFrameRect();
  point_t left_down = getLeftDownPoint(rectangle);
  point_t right_up = getRightUpPoint(rectangle);
  double x_min = left_down.x;
  double y_min = left_down.y;
  double x_max = right_up.x;
  double y_max = right_up.y;
  for (size_t i = 0; i < count_; i++)
  {
    rectangle = triangles_[i].getFrameRect();
    left_down = getLeftDownPoint(rectangle);
    right_up = getRightUpPoint(rectangle);
    x_min = std::min(x_min, left_down.x);
    y_min = std::min(y_min, left_down.y);
    x_max = std::max(x_max, right_up.x);
    y_max = std::max(y_max, right_up.y);
  }
  return rectangle_t(point_t{x_min, y_min}, point_t{x_max, y_max});
}
void dimkashelk::Polygon::move(point_t point)
{
  move(point.x - center_.x, point.y - center_.y);
}
void dimkashelk::Polygon::move(double delta_x, double delta_y)
{
  for (size_t i = 0; i < count_; i++)
  {
    triangles_[i].move(delta_x, delta_y);
  }
  center_.x += delta_x;
  center_.y += delta_y;
}
void dimkashelk::Polygon::scale(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Coefficient below zero");
  }
  for (size_t i = 0; i < count_; i++)
  {
    isotropicScaling(&triangles_[i], center_, k);
  }
}
dimkashelk::Shape* dimkashelk::Polygon::clone() const
{
  return new Polygon(*this);
}
