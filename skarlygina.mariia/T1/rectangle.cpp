#include "rectangle.h"
#include <cmath>
#include <stdexcept>
Rectangle::Rectangle(point_t left_down, point_t right_up):
  left_down_(left_down),
  right_up_(right_up)
{
  if (isBadRectangle())
  {
    throw std::invalid_argument("Error: false rectangle parameters");
  }
}

bool Rectangle::isBadRectangle()
{
  return (left_down_.x >= right_up_.x || left_down_.y >= right_up_.y);
}

rectangle_t Rectangle::getFrameRectangle() const
{
  point_t side = baseFunctions::findDifference(right_up_, left_down_);
  point_t position = {(left_down_.x + right_up_.x) / 2, (left_down_.y + right_up_.y) / 2};
  return {side.y, side.x, position};
}

double Rectangle::getArea() const
{
  double area_rectangle = getFrameRectangle().width * getFrameRectangle().height;
  return area_rectangle;
}

void Rectangle::move(double dx, double dy)
{
  left_down_ = baseFunctions::findSummVector(left_down_, dx, dy);
  right_up_ = baseFunctions::findSummVector(right_up_, dx, dy);
}

void Rectangle::move(point_t position)
{
  point_t diff = baseFunctions::findDifference(position, getFrameRectangle().position);
  move(diff.x, diff.y);
}

void Rectangle::scale(double k)
{
  baseFunctions::findCorrectKoeff(k);
  point_t center = getFrameRectangle().position;
  left_down_ = baseFunctions::makeScale(left_down_, center, k);
  right_up_ = baseFunctions::makeScale(right_up_, center, k);
}
