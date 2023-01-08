#include "Rectangle.h"
#include <stdexcept>

Rectangle::Rectangle(point_t left, point_t right) :
  left(left),
  right(right)
{
  if (left.x > right.x && left.y > right.y)
  {
    throw std::invalid_argument("incorrect input");
  }
}