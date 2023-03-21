#include "Concave.hpp"
#include <stdexcept>
#include <algorithm>
#include <cmath>

Concave::Concave(point_t one, point_t two, point_t three, point_t four):
  dots_{one, two, three, four}
{
  if (validateConcave(dots_))
  {
    throw std::invalid_argument("Bad input, invalid concave size");
  }
}

std::array< double, 6 > Concave::calcWithTriangles() const
{
  double vec_a = calcVectorLength(dots_[0], dots_[2]);
  double vec_b = calcVectorLength(dots_[2], dots_[1]);
  double vec_c = calcVectorLength(dots_[0], dots_[1]);
  double vec_a1 = calcVectorLength(dots_[2], dots_[3]);
  double vec_b1 = vec_b;
  double vec_c1 = calcVectorLength(dots_[3], dots_[1]);
  std::array< double, 6 > segments = {vec_a, vec_b, vec_c, vec_a1, vec_b1, vec_c1};
  return segments;
}

double Concave::getArea() const
{
  std::array< double, 6 > segments = calcWithTriangles();
  double a = segments[0];
  double b = segments[1];
  double c = segments[2];
  double a1 = segments[3];
  double b1 = segments[4];
  double c1 = segments[5];
  double p = (a + b + c) / 2;
  double p1 = (a1 + b1 + c1) / 2;
  double s = std::sqrt(p * (p - a) * (p - b) * (p - c));
  double s1 = std::sqrt(p1 * (p1 - a1) * (p1 - b1) * (p1 - c1));
  return (s - s1);
}

rectangle_t Concave::getFrameRect() const
{
  double top = std::max({dots_[0].y, dots_[1].y, dots_[2].y});
  double bottom = std::min({dots_[0].y, dots_[1].y, dots_[2].y});
  double left = std::min({dots_[0].x, dots_[1].x, dots_[2].x});
  double right = std::max({dots_[0].x, dots_[1].x, dots_[2].x});
  return {{(right + left) / 2, (top + bottom) / 2}, right - left, top - bottom};
}

void Concave::move(point_t position)
{
  double dx = position.x - getFrameRect().pos.x;
  double dy = position.y - getFrameRect().pos.y;
  move(dx, dy);
}

void Concave::move(double dx, double dy)
{
  for (point_t &dot: dots_)
  {
    dot = addVector(dot, dx, dy);
  }
}

void Concave::makeScale(double k)
{
  point_t center = getFrameRect().pos;
  for (point_t &dot: dots_)
  {
    dot.x = k * (dot.x - center.x) + center.x;
    dot.y = k * (dot.y - center.y) + center.y;
  }
}

Shape *Concave::clone() const
{
  return new Concave(dots_[0], dots_[1], dots_[2], dots_[3]);
}
