#include "ellipse.h"
#include <stdexcept>
Ellipse::Ellipse(point_t center, double radius_vertical, double radius_horizontal):
  center_(center),
  radius_vertical_(radius_vertical),
  radius_horizontal_(radius_horizontal)
{
  if (isBadEllipse())
  {
    throw std::invalid_argument("Error: false ellipse parameters");
  }
}

bool Ellipse::isBadEllipse()
{
  return (radius_horizontal_ <= 0 || radius_vertical_ <= 0);
}

double Ellipse::getArea() const
{
  const double pi = 3.1416;
  return (pi * radius_vertical_ * radius_horizontal_);
}
rectangle_t Ellipse::getFrameRectangle() const
{
  double height = baseFunctions::findRadius(radius_vertical_, 2.0);
  double width = baseFunctions::findRadius(radius_horizontal_, 2.0);
  point_t position = {center_.x, center_.y};
  return {height, width, position};
}

void Ellipse::move(double dx, double dy)
{
  center_ = baseFunctions::findSummVector(center_, dx, dy);
}

void Ellipse::move(point_t position)
{
  point_t diff = baseFunctions::findDifference(position, getFrameRectangle().position);
  move(diff.x, diff.y);
}

void Ellipse::scale(double k)
{
  baseFunctions::findCorrectKoeff(k);
  point_t center = getFrameRectangle().position;
  radius_horizontal_ = baseFunctions::findRadius(radius_horizontal_, k);
  radius_vertical_ = baseFunctions::findRadius(radius_vertical_, k);
  center_ = baseFunctions::makeCenterMove(center_, center, k);
}
