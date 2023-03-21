#include "shape.h"
void dimkashelk::Shape::scale(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Coefficient below zero");
  }
  unsafeScale(k);
}
