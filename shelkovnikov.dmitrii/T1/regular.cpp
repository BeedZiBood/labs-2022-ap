#include "regular.h"
#include <stdexcept>
#include "isotropic_scaling.h"
#include "base_functions.h"
dimkashelk::Regular::Regular(point_t point_1, point_t point_2, point_t point_3):
  triangle_(point_1, point_2, point_3),
  size_(getCountTriangles(point_1, point_2, point_3)),
  center_(point_1)
{
  point_t points[3]{point_1, point_2, point_3};
  if (!isRectangularTriangle(points))
  {
    throw std::logic_error("Triangle isn't rectangular");
  }
}
dimkashelk::Regular::Regular(const Regular &regular):
  triangle_(regular.triangle_),
  size_(regular.size_),
  center_(regular.center_)
{}
double dimkashelk::Regular::getArea() const
{
  return triangle_.getArea() * size_;
}
dimkashelk::rectangle_t dimkashelk::Regular::getFrameRect() const
{
  rectangle_t rectangle = triangle_.getFrameRect();
  point_t left_down = getLeftDownPoint(rectangle);
  point_t right_up = getRightUpPoint(rectangle);
  double min_x = left_down.x;
  double min_y = left_down.y;
  double max_x = right_up.x;
  double max_y = right_up.y;
  double theta = 360.0 / size_ * 2 * PI / 180;
  for (size_t i = 1; i < size_; i++)
  {
    Triangle rotate_triangle = triangle_.rotate(i * theta);
    rectangle = rotate_triangle.getFrameRect();
    left_down = getLeftDownPoint(rectangle);
    right_up = getRightUpPoint(rectangle);
    min_x = std::min(min_x, left_down.x);
    min_y = std::min(min_y, left_down.y);
    max_x = std::max(max_x, right_up.x);
    max_y = std::max(max_y, right_up.y);
  }
  return makeRectangle(point_t{min_x, min_y}, point_t{max_x, max_y});
}
void dimkashelk::Regular::move(double delta_x, double delta_y)
{
  triangle_.move(delta_x, delta_y);
}
void dimkashelk::Regular::move(point_t point)
{
  Triangle triangle = Triangle(triangle_);
  triangle.move(center_);
  point_t begin_point = getLeftDownPoint(triangle.getFrameRect());
  triangle.move(point);
  point_t end_point = getLeftDownPoint(triangle.getFrameRect());
  double delta_x = end_point.x - begin_point.x;
  double delta_y = end_point.y - begin_point.y;
  triangle_.move(delta_x, delta_y);
  center_.x += delta_x;
  center_.y += delta_y;
}
dimkashelk::Shape *dimkashelk::Regular::clone() const
{
  return new Regular(*this);
}
void dimkashelk::Regular::unsafeScale(double k) noexcept
{
  unsafeIsotropicScaling(std::addressof(triangle_), center_, k);
}
