#include "complexquad.hpp"
#include <stdexcept>
#include "triangle.hpp"
#include "base-func.hpp"
#include "isoscale.hpp"

tarasenko::Complexquad::Complexquad(point_t point_1, point_t point_2, point_t point_3, point_t point_4):
  triangle_1({0, 0}, {1, 1}, {1, 0}),
  triangle_2({0, 0}, {1, 1}, {1, 0}),
  p_cross{0, 0}
{
  try
  {
    double a1 = point_2.y_ - point_1.y_;
    double b1 = point_1.x_ - point_2.x_;
    double c1 = -point_1.x_ * point_2.y_ + point_1.y_ * point_2.x_;
    double a2 = point_4.y_ - point_3.y_;
    double b2 = point_3.x_ - point_4.x_;
    double c2 = -point_3.x_ * point_4.y_ + point_3.y_ * point_4.x_;
    if ((a1 * b2 - a2 * b1) == 0 || (a1 * b2 == b1 * a2 && a1 * c2 == a2 * c1 && b1 * c2 == c1 * b2))
    {
      throw;
    }
    p_cross.x_ = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1);
    p_cross.y_ = (a2 * c1 - a1 * c2) / (a1 * b2 - a2 * b1);
    triangle_1 = Triangle(point_1, point_4, p_cross);
    triangle_2 = Triangle(point_2, point_3, p_cross);
  }
  catch (...)
  {
    throw std::invalid_argument("incorrect complexquad coordinates");
  }
}

tarasenko::Complexquad::Complexquad(Triangle tr_1,Triangle tr_2):
  triangle_1(tr_1),
  triangle_2(tr_2)
{}

double tarasenko::Complexquad::getArea() const
{
  return triangle_1.getArea() + triangle_2.getArea();
}

tarasenko::rectangle_t tarasenko::Complexquad::getFrameRect() const
{
  point_t point_ld_rect_1 = getPointLDRect(triangle_1.getFrameRect());
  point_t point_ru_rect_1 = getPointRURect(triangle_1.getFrameRect());
  point_t points_ld_rect_2 = getPointLDRect(triangle_2.getFrameRect());
  point_t points_ru_rect_2 = getPointRURect(triangle_2.getFrameRect());
  double min_x = std::min(point_ld_rect_1.x_, points_ld_rect_2.x_);
  double min_y = std::min(point_ld_rect_1.y_, points_ld_rect_2.y_);
  double max_x = std::max(point_ru_rect_1.x_, points_ru_rect_2.x_);
  double max_y = std::max(point_ru_rect_1.y_, points_ru_rect_2.y_);
  return makeRectangle(point_t{min_x, min_y},point_t{max_x, max_y});;
}

void tarasenko::Complexquad::move(double dx, double dy)
{
  triangle_1.move(dx, dy);
  triangle_2.move(dx, dy);
}

void tarasenko::Complexquad::move(point_t pos)
{
  this->move(pos.x_ - p_cross.x_, pos.y_ - p_cross.y_);
}

void tarasenko::Complexquad::scale(double k)
{
  isoScale(std::addressof(triangle_1), {0, 0}, k);
  isoScale(std::addressof(triangle_2), {0, 0}, k);
}

tarasenko::Shape * tarasenko::Complexquad::clone() const
{
  return new Complexquad(triangle_1, triangle_2);
}
