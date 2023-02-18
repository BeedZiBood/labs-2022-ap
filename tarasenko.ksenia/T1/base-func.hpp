#ifndef BASEFUNC_HPP
#define BASEFUNC_HPP
#include "base-types.hpp"

namespace tarasenko
{
  rectangle_t makeRectangle(point_t point_ld, point_t point_ru);
  point_t getPointLDRect(rectangle_t rect);
  point_t getPointRURect(rectangle_t rect);
};
#endif
