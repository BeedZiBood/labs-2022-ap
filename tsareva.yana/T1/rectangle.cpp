#include "rectangle.h"
Rectangle::Rectangle(point_t left_down, point_t right_up):
  left_down_(left_down),
  right_up_(right_up)
{

}

double Rectangle::getArea() const
{
  double area_rectangle = gerFrameRectangle().width * gerFrameRectangle().height;
  return area_rectangle;
}
