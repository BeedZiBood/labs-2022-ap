#include "triangle.h"

Triangle::Triangle(const point_t& A, const point_t& B, const point_t& C):
  A_(A),
  B_(B),
  C_(C)
{
  if (!isCorrectTriangle(A, B, C))
  {
    throw std::invalid_argument("invalid triangle");
  }
}

std::string Triangle::getName() const
{
  return "TRIANGLE";
}

double Triangle::getArea() const
{
  double ab_side = getSide(A_, B_);
  double ac_side = getSide(A_, C_);
  double bc_side = getSide(C_, B_);
  double halfmeter = (ab_side + ac_side + bc_side) / 2;
  return std::sqrt(halfmeter * (halfmeter - ab_side) * (halfmeter - ac_side) * (halfmeter - bc_side));
}

rectangle_t Triangle::getFrameRect() const
{
  double x_min = std::min(A_.x, std::min(B_.x, C_.x));
  double y_min = std::min(A_.y, std::min(B_.y, C_.y));
  double x_max = std::max(A_.x, std::max(B_.x, C_.x));
  double y_max = std::max(A_.y, std::max(B_.y, C_.y));
  point_t leftPoint{ x_min, y_min };
  point_t rightPoint{ x_max, y_max };
  point_t pos{ (leftPoint.x + rightPoint.x) / 2, (leftPoint.y + rightPoint.y) / 2 };
  return { rightPoint.x - leftPoint.x, rightPoint.y - leftPoint.y, pos };
}

void Triangle::move(const point_t& point)
{
  point_t pos = getCenterTriangle(A_, B_, C_);
  double dx = point.x - pos.x;
  double dy = point.y - pos.y;
  move(dx, dy);
}

void Triangle::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("invalid k scale");
  }
  point_t pos = getCenterTriangle(A_, B_, C_);
  A_ = scalePoint(A_, pos, k);
  B_ = scalePoint(B_, pos, k);
  C_ = scalePoint(C_, pos, k);
}

void Triangle::move(double dx, double dy)
{
  point_t dpoint{ dx, dy };
  A_ = movePoint(A_, dpoint);
  B_ = movePoint(B_, dpoint);
  C_ = movePoint(C_, dpoint);
}

Shape* Triangle::clone() const
{
  return new Triangle(A_, B_, C_);
}
