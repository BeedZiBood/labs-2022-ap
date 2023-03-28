#include "shape.h"

void chulkov::Shape::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Error: invalid scale");
  }
  return unsafeScale(k);
}
