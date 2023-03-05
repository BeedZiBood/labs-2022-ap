#include "parallelogram.h"

Parallelogram::Parallelogram(const point_t& A, const point_t& B, const point_t& C):
  A_(A),
  B_(B),
  C_(C)
{
  if (!isCorrectParallelogram(A, B, C))
  {
    throw std::invalid_argument("invalid rectangle");
  }
}

std::string Parallelogram::getName() const
{
  return "PARALLELOGRAM";
}

double Parallelogram::getArea() const
{
  double side1 = getSide(A_, B_);
  double side2 = getSide(A_, C_);
  double side3 = getSide(C_, B_);
  double halfmeter = (side1 + side2 + side3) / 2;
  return 2 * std::sqrt(halfmeter * (halfmeter - side1) * (halfmeter - side2) * (halfmeter - side3));
}

rectangle_t Parallelogram::getFrameRect() const
{
  double leftPointX = std::min(A_.x, std::min(B_.x, C_.x));
  double rightPointX = std::max(A_.x, std::max(B_.x, C_.x));
  double lowestPointY = std::min(A_.y, std::min(B_.y, C_.y));
  double highestPointY = std::max(A_.y, std::max(B_.y, C_.y));
  return { rightPointX - leftPointX, highestPointY - lowestPointY, getCenterParallelogram(A_, C_) };
}

void Parallelogram::move(const point_t& point)
{
  point_t pos = getCenterParallelogram(A_, C_);
  double dx = point.x - pos.x;
  double dy = point.y - pos.y;
  move(dx, dy);
}

void Parallelogram::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Invalid k size");
  }
  point_t pos = getCenterParallelogram(A_, C_);
  A_ = scalePoint(A_, pos, k);
  B_ = scalePoint(B_, pos, k);
  C_ = scalePoint(C_, pos, k);
}

void Parallelogram::move(double dx, double dy)
{
  point_t dpoint{ dx, dy };
  A_ = movePoint(A_, dpoint);
  B_ = movePoint(B_, dpoint);
  C_ = movePoint(C_, dpoint);
}

Shape* Parallelogram::clone() const
{
  return new Parallelogram(A_, B_, C_);
}
