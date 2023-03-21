#include "rectangle.h"

Rectangle::Rectangle(const point_t& ld_point, const point_t& ru_point):
  ld_point_(ld_point),
  ru_point_(ru_point)
{
  if (!isCorrectRectangle(ld_point, ru_point))
  {
    throw std::invalid_argument("invalid rectangle");
  }
}

double Rectangle::getArea() const
{
  return getFrameRect().width * getFrameRect().height;
}

std::string Rectangle::getName() const
{
  return "RECTANGLE";
}

rectangle_t Rectangle::getFrameRect() const
{
  double width = ru_point_.x - ld_point_.x;
  double height = ru_point_.y - ld_point_.y;
  return { width, height, getCenterRectangle(ld_point_, ru_point_) };
}

void Rectangle::move(const point_t& point)
{
  point_t pos = getCenterRectangle(ld_point_, ru_point_);
  double dx = point.x - pos.x;
  double dy = point.y - pos.y;
  move(dx, dy);
}

void Rectangle::move(const double dx, const double dy)
{
  point_t dpoint{ dx, dy };
  ld_point_ = movePoint(ld_point_, dpoint);
  ru_point_ = movePoint(ru_point_, dpoint);
}

void Rectangle::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Invalid k size");
  }
  point_t pos = getCenterRectangle(ld_point_, ru_point_);
  ld_point_ = scalePoint(ld_point_, pos, k);
  ru_point_ = scalePoint(ru_point_, pos, k);
}

Shape* Rectangle::clone() const
{
  return new Rectangle(ld_point_, ru_point_);
}
