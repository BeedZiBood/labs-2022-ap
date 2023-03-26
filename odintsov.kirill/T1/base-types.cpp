#include "base-types.hpp"
#include <cstddef>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include "shape.hpp"

odintsov::FrameRectBuilder::FrameRectBuilder(const point_t& p):
  bl_(p),
  tr_(p)
{}

odintsov::FrameRectBuilder::FrameRectBuilder(const rectangle_t& r):
  bl_(getFrameRectBottomLeftCorner(r)),
  tr_(getFrameRectTopRightCorner(r))
{}

odintsov::FrameRectBuilder& odintsov::FrameRectBuilder::operator<<(const point_t& p)
{
  bl_.x = std::min(bl_.x, p.x);
  bl_.y = std::min(bl_.y, p.y);
  tr_.x = std::max(tr_.x, p.x);
  tr_.y = std::max(tr_.y, p.y);
  return *this;
}

odintsov::FrameRectBuilder& odintsov::FrameRectBuilder::operator<<(const rectangle_t& r)
{
  return *this << getFrameRectBottomLeftCorner(r) << getFrameRectTopRightCorner(r);
}

odintsov::rectangle_t odintsov::FrameRectBuilder::rect()
{
  return getFrameRectFromCorners(bl_, tr_);
}

void odintsov::movePoint(point_t& p, double dx, double dy)
{
  p.x += dx;
  p.y += dy;
}

void odintsov::isoScalePoint(point_t& p, const point_t& anchor, double k)
{
  assertValidScaling(k);
  movePoint(p, (p.x - anchor.x) * (k - 1.0), (p.y - anchor.y) * (k - 1.0));
}

odintsov::rectangle_t odintsov::getFrameRectFromCorners(const point_t& bl, const point_t& tr)
{
  if (tr.x < bl.x || tr.y < bl.y) {
    throw std::invalid_argument("corners set incorrectly");
  }
  return rectangle_t{tr.x - bl.x, tr.y - bl.y, {(bl.x + tr.x) * 0.5, (bl.y + tr.y) * 0.5}};
}

odintsov::point_t odintsov::getFrameRectBottomLeftCorner(const rectangle_t& rect)
{
  return point_t{rect.pos.x - rect.width * 0.5, rect.pos.y - rect.height * 0.5};
}

odintsov::point_t odintsov::getFrameRectTopRightCorner(const rectangle_t& rect)
{
  return point_t{rect.pos.x + rect.width * 0.5, rect.pos.y + rect.height * 0.5};
}

std::ostream& odintsov::outputFrameRect(std::ostream& out, const rectangle_t& rect)
{
  point_t bl = getFrameRectBottomLeftCorner(rect);
  point_t tr = getFrameRectTopRightCorner(rect);
  return out << bl.x << ' ' << bl.y << ' ' << tr.x << ' ' << tr.y;
}

bool odintsov::isPointInRectangle(const point_t& p, const rectangle_t& rect)
{
  point_t bl = getFrameRectBottomLeftCorner(rect);
  point_t tr = getFrameRectTopRightCorner(rect);
  return bl.x <= p.x && p.x <= tr.x && bl.y <= p.y && p.y <= tr.y;
}
