#include "triangle.hpp"
#include <stdexcept>
#include <cmath>
#include "base-func.hpp"

tarasenko::Triangle::Triangle(point_t point_1, point_t point_2, point_t point_3):
  vertexes{point_1, point_2, point_3}
{
  double * sides = getSides(point_1, point_2, point_3);
  if (sides[0] >= sides[1] + sides[2] || sides[1] >= sides[0] + sides[2] || sides[2] >= sides[0] + sides[1])
  {
    throw std::invalid_argument("incorrect triangle coordinates");
  }
}

tarasenko::point_t tarasenko::Triangle::getCenter() const
{
  return point_t{(vertexes[0].x_ + vertexes[1].x_ + vertexes[2].x_) / 3, (vertexes[0].y_ + vertexes[1].y_ + vertexes[2].y_) / 3};
}

double * tarasenko::Triangle::getSides(point_t point_1, point_t point_2, point_t point_3) const
{
  static double sides[3];
  sides[0] = std::sqrt(std::pow((point_2.x_ - point_1.x_),2) + std::pow((point_2.y_ - point_1.y_),2));
  sides[1] = std::sqrt(std::pow((point_3.x_ - point_1.x_),2) + std::pow((point_3.y_ - point_1.y_),2));
  sides[2] = std::sqrt(std::pow((point_3.x_ - point_2.x_),2) + std::pow((point_3.y_ - point_2.y_),2));
  return sides;
}

double tarasenko::Triangle::getArea() const
{
  double * sides = getSides(vertexes[0], vertexes[1], vertexes[2]);
  double pp = (sides[0] + sides[1] + sides[2]) / 2;
  return std::sqrt(pp * (pp - sides[0]) * (pp - sides[1]) * (pp - sides[2]));
}

tarasenko::rectangle_t tarasenko::Triangle::getFrameRect() const
{
  double min_x = std::min(std::min(vertexes[0].x_, vertexes[1].x_), vertexes[2].x_);
  double min_y = std::min(std::min(vertexes[0].y_, vertexes[1].y_), vertexes[2].y_);
  double max_x = std::max(std::max(vertexes[0].x_, vertexes[1].x_), vertexes[2].x_);
  double max_y = std::max(std::max(vertexes[0].y_, vertexes[1].y_), vertexes[2].y_);
  return makeRectangle(point_t{min_x, min_y},point_t{max_x, max_y});
}

void tarasenko::Triangle::move(double dx, double dy)
{
  for (size_t i = 0; i < 3; i++)
  {
    vertexes[i] = vertexes[i] + point_t{dx, dy};
  }
}

void tarasenko::Triangle::move(point_t pos)
{
  point_t center = getCenter();
  this->move(pos.x_ - center.x_,pos.y_ - center.y_);
}

void tarasenko::Triangle::scale(double k)
{
  this->checkCoefficient(k);
  point_t center = getCenter();
  for (size_t i = 0; i < 3; i++)
  {
    vertexes[i].x_ = center.x_ + (vertexes[i].x_ - center.x_) * k;
    vertexes[i].y_ = center.y_ + (vertexes[i].y_ - center.y_) * k;
  }
}

tarasenko::Shape * tarasenko::Triangle::clone() const
{
  return new Triangle(vertexes[0], vertexes[1], vertexes[2]);
}
