#include "concave.hpp"
#include <stdexcept>
#include "shape.hpp"
#include "line.hpp"
#include "triangle.hpp"
#include "base-types.hpp"

odintsov::Concave::Concave(const point_t& p1, const point_t& p2, const point_t& p3, const point_t& p4):
  p1_(p1),
  p2_(p2),
  p3_(p3),
  p4_(p4)
{
  if (!(isTriangle(p1_, p2_, p3_) && isPointStrictlyInsideTriangle(p4_, p1_, p2_, p3_))) {
    throw std::invalid_argument("points are set incorrectly");
  }
}

double odintsov::Concave::getArea() const
{
  return getTriangleArea(p1_, p4_, p2_) + getTriangleArea(p1_, p4_, p3_);
}

odintsov::rectangle_t odintsov::Concave::getFrameRect() const
{
  return (FrameRectBuilder(p1_) << p2_ << p3_ << p4_).rect();
}

void odintsov::Concave::move(double dx, double dy)
{
  movePoint(p1_, dx, dy);
  movePoint(p2_, dx, dy);
  movePoint(p3_, dx, dy);
  movePoint(p4_, dx, dy);
}

void odintsov::Concave::move(const point_t& pos)
{
  point_t middle = getMiddlePoint();
  move(pos.x - middle.x, pos.y - middle.y);
}

void odintsov::Concave::scale(double k)
{
  assertValidScaling(k);
  point_t middle = getMiddlePoint();
  isoScalePoint(p1_, middle, k);
  isoScalePoint(p2_, middle, k);
  isoScalePoint(p3_, middle, k);
  isoScalePoint(p4_, middle, k);
}

odintsov::point_t odintsov::Concave::getMiddlePoint() const
{
  return p4_;
}

odintsov::Concave* odintsov::Concave::clone() const
{
  return new Concave(p1_, p2_, p3_, p4_);
}
