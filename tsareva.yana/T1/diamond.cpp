#include "diamond.h"
#include <stdexcept>

Diamond::Diamond(point_t first, point_t second, point_t third):
  first_(first),
  second_(second),
  third_(third)
{
  if (!(isDiamond(first, second, third)))
  {
    throw std::invalid_argument("Error diamond parameters");
  }
  if (second_.y == third_.y)
  {
    first_ = third;
    third_ = first;
  }
  if (first_.y == third_.y)
  {
    second_ = third;
    third_ = second;
  }
}
