#include "complexquad.hpp"
#include <stdexcept>
#include "base-types.hpp"
#include "shape.hpp"
#include "triangle.hpp"
#include "line.hpp"
#include "nearlyEquals.hpp"

odintsov::ComplexQuad::ComplexQuad(const point_t& p1, const point_t& p2, const point_t& p3, const point_t& p4):
  p1_(p1),
  p2_(p2),
  p3_(p3),
  p4_(p4)
{
  point_t ip = getIntersectionPoint();
  const double e = 0.00001;
  if (nearlyEquals(ip, p1_, e) || nearlyEquals(ip, p2_, e) || nearlyEquals(ip, p3_, e) || nearlyEquals(ip, p4_, e)) {
    throw std::invalid_argument("points set incorrectly");
  }
}

double odintsov::ComplexQuad::getArea() const
{
  point_t ip = getIntersectionPoint();
  return getTriangleArea(p1_, p4_, ip) + getTriangleArea(p2_, p3_, ip);
}

odintsov::rectangle_t odintsov::ComplexQuad::getFrameRect() const
{
  return (FrameRectBuilder(p1_) << p2_ << p3_ << p4_).rect();
}

void odintsov::ComplexQuad::move(double dx, double dy)
{
  movePoint(p1_, dx, dy);
  movePoint(p2_, dx, dy);
  movePoint(p3_, dx, dy);
  movePoint(p4_, dx, dy);
}

void odintsov::ComplexQuad::move(const point_t& pos)
{
  point_t middle = getMiddlePoint();
  move(pos.x - middle.x, pos.y - middle.y);
}

void odintsov::ComplexQuad::scale(double k)
{
  assertValidScaling(k);
  point_t middle = getMiddlePoint();
  isoScalePoint(p1_, middle, k);
  isoScalePoint(p2_, middle, k);
  isoScalePoint(p3_, middle, k);
  isoScalePoint(p4_, middle, k);
}

odintsov::point_t odintsov::ComplexQuad::getMiddlePoint() const
{
  return getIntersectionPoint();
}

odintsov::point_t odintsov::ComplexQuad::getIntersectionPoint() const
{
  return getLineSegIntersectionPoint(p1_, p2_, p3_, p4_);
}

odintsov::ComplexQuad* odintsov::ComplexQuad::clone() const
{
  return new ComplexQuad(p1_, p2_, p3_, p4_);
}
