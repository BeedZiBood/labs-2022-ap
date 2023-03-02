#include "parallelogram.hpp"
#include <stdexcept>
#include <cmath>
#include "base-types.hpp"

zasulsky::Parallelogram::Parallelogram(const point_t& p1, const point_t& p2, const point_t& p3) :
  p1_(p1),
  p2_(p2),
  p3_(p3)
{
  bool side12Incorrect = (abs(p2_.x - p1_.x) <= 0.0 && abs(p2_.y - p1_.y) <= 0.0);
  bool side23Incorrect = (abs(p3_.x - p2_.x) <= 0.0 && abs(p3_.y - p2_.y) <= 0.0);
  bool side13Incorrect = (abs(p3_.x - p1_.x) <= 0.0 && abs(p3_.y - p1_.y) <= 0.0);
  if (side12Incorrect || side23Incorrect || side13Incorrect)
  {
    throw std::invalid_argument("Sides should be bigger than 0.0");
  }
}
double zasulsky::Parallelogram::getArea() const
{
  if (p1_.y == p2_.y)
  {
    return (abs(p1_.y - p3_.y)) * abs(p2_.x - p1_.x);
  }
  return (abs(p1_.y - p3_.y)) * abs(p2_.x - p3_.x);
}
zasulsky::point_t zasulsky::Parallelogram::getCenter() const
{
  point_t location;
  location.x = abs((p1_.x + p3_.x) * 0.5);
  location.y = abs((p1_.y + p3_.y) * 0.5);
  return location;
}
zasulsky::rectangle_t zasulsky::Parallelogram::getFrameRect() const
{
  point_t location = getCenter();
  double side12x = p2_.x - p1_.x;
  double side12y = p2_.y - p1_.y;
  double side23x = p3_.x - p2_.x;
  double side13y = p1_.y - p3_.y;
  return rectangle_t{ abs(side12x) + abs(side23x), abs(side13y), location };
}
void zasulsky::Parallelogram::move(double dx, double dy)
{
  movePoint(p1_, dx, dy);
  movePoint(p2_, dx, dy);
  movePoint(p3_, dx, dy);
}
void zasulsky::Parallelogram::move(const zasulsky::point_t& position)
{
  point_t location = getCenter();
  move(position.x - location.x, position.y - location.y);
}
void zasulsky::Parallelogram::scale(double k)
{
  point_t location = getCenter();
  isoScalePoint(p1_, location, k);
  isoScalePoint(p2_, location, k);
  isoScalePoint(p3_, location, k);
}
