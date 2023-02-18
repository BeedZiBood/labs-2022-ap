#include "base-types.hpp"

tarasenko::point_t tarasenko::operator+(const point_t & point_1, const point_t & point_2)
{
  return {point_1.x_ + point_2.x_, point_1.y_ + point_2.y_};
}
