#include "rectangle.h"
#include <stdexcept>
Rectangle::Rectangle(point_t left_down, point_t right_up):
  left_down_(left_down),
  right_up_(right_up)
{
  if (left_down_.x >= right_up_.x || left_down_.y >= right_up_.y)
  {
    throw std::invalid_argument("Error rectangle parameters");
  }
}


void Rectangle::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Error ratio");
  }

}

double Rectangle::getArea() const
{
  return gerFrameRectangle().width * gerFrameRectangle().height;
}
