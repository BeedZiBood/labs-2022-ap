#include "concave.h"
#include <stdexcept>
#include "triangle.h"
#include "supportFunctions.h"

Concave::Concave(const point_t &point1, const point_t &point2, const point_t &point3, const point_t &point4):
  p1_(point1),
  p2_(point2),
  p3_(point3),
  p4_(point4)
{
  if (!isTriangle(p1_, p2_, p3_) || !isPointInsideTriangle(p1_, p2_, p3_, p4_)) {
    throw std::invalid_argument("It`s not a concave");
  }
}

double Concave::getArea() const
{
  return getTriangleArea(p1_, p2_, p3_) - getTriangleArea(p2_, p3_, p4_);
}

rectangle_t Concave::getFrameRect() const
{
  double leftX = std::min(p1_.x, std::min(p2_.x, p3_.x));
  double rightX = std::max(p1_.x, std::max(p2_.x, p3_.x));
  double bottomY = std::min(p1_.y, std::min(p2_.y, p3_.y));
  double topY = std::max(p1_.y, std::max(p2_.y, p3_.y));
  return {rightX - leftX, topY - bottomY, {(leftX + rightX) * 0.5, (bottomY + topY) * 0.5}};
}

void Concave::move(double dx, double dy)
{
  movePoint(p1_, dx, dy);
  movePoint(p2_, dx, dy);
  movePoint(p3_, dx, dy);
  movePoint(p4_, dx, dy);
}

void Concave::move(const point_t &pos)
{
  move(pos.x - p4_.x, pos.y - p4_.y);
}

void Concave::scale(double k)
{
  if (k <= 0) {
    throw std::invalid_argument("Ratio must be greater than 0");
  }
  movePointBecauseOfScale(p1_, p4_, k);
  movePointBecauseOfScale(p2_, p4_, k);
  movePointBecauseOfScale(p3_, p4_, k);
}
