#include "rectangle.h"
#include <stdexcept>

tsareva::Rectangle::Rectangle(point_t l_d, point_t r_up):
  rectangle_{r_up.y - l_d.y, r_up.x - l_d.x, {(r_up.x + l_d.x) / 2, (r_up.y + l_d.y) / 2}}
{
  if (rectangle_.height <= 0 || rectangle_.width <= 0)
  {
    throw std::invalid_argument("Error rectangle parameters");
  }
}

void tsareva::Rectangle::move(double dx, double dy)
{
  rectangle_.pos.x += dx;
  rectangle_.pos.y += dy;
}

void tsareva::Rectangle::move(point_t position)
{
  rectangle_.pos = position;
}

void tsareva::Rectangle::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Error ratio");
  }
  rectangle_.height *= k;
  rectangle_.width *=k;
}

double tsareva::Rectangle::getArea() const
{
  return rectangle_.width * rectangle_.height;
}

tsareva::rectangle_t tsareva::Rectangle::getFrameRectangle() const
{
  return rectangle_;
}