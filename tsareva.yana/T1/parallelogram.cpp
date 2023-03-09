#include "parallelogram.h"
#include <stdexcept>

Parallelogram::Parallelogram(point_t first, point_t second, point_t third):
  first_(first),
  second_(second),
  third_(third)
{
  if(!((first_.y == second_.y) || (second_.y == third_.y)))
  {
    throw std::invalid_argument("Error parallelogram parameters");
  }
}
