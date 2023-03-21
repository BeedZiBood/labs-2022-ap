#include "complexquad.h"
#include <stdexcept>
#include <algorithm>
#include "supportFunctions.h"
#include "triangle.h"

Complexquad::Complexquad(const point_t &point1, const point_t &point2, const point_t &point3, const point_t &point4):
  p1_(point1),
  p2_(point2),
  p3_(point3),
  p4_(point4)
{
  if (!isIntersectionOfSegments(p1_, p2_, p3_, p4_)) {
    throw std::invalid_argument("It`s not a complexquad");
  }
}

double Complexquad::getArea() const
{
  point_t center = getIntersectionPoint(p1_, p2_, p3_, p4_);
  return getTriangleArea(p1_, p4_, center) + getTriangleArea(p2_, p3_, center);
}

rectangle_t Complexquad::getFrameRect() const
{
  double leftX = std::min(std::min(p1_.x, p4_.x), std::min(p2_.x, p3_.x));
  double rightX = std::max(std::max(p1_.x, p4_.x), std::max(p2_.x, p3_.x));
  double bottomY = std::min(std::min(p1_.y, p4_.y), std::min(p2_.y, p3_.y));
  double topY = std::max(std::max(p1_.y, p4_.y), std::max(p2_.y, p3_.y));
  return {rightX - leftX, topY - bottomY, {(leftX + rightX) * 0.5, (bottomY + topY) * 0.5}};
}

void Complexquad::move(double dx, double dy)
{
  movePoint(p1_, dx, dy);
  movePoint(p2_, dx, dy);
  movePoint(p3_, dx, dy);
  movePoint(p4_, dx, dy);
}

void Complexquad::move(const point_t& pos)
{
  point_t center = getIntersectionPoint(p1_, p2_, p3_, p4_);
  move(pos.x - center.x, pos.y - center.y);
}

void Complexquad::scale(double k)
{
  if (k <= 0) {
    throw std::invalid_argument("Ratio must be greater than 0");
  }
  point_t center = getIntersectionPoint(p1_, p2_, p3_, p4_);
  movePointBecauseOfScale(p1_, center, k);
  movePointBecauseOfScale(p2_, center, k);
  movePointBecauseOfScale(p3_, center, k);
  movePointBecauseOfScale(p4_, center, k);
}
