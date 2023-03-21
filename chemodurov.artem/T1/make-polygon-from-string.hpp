#ifndef MAKE_POLYGON_FROM_STRING_HPP
#define MAKE_POLYGON_FROM_STRING_HPP
#include <string>
#include "base-types.hpp"

namespace chemodurov
{
  point_t * getArrayOfPoints(const std::string & data, size_t pos, size_t & arr_size);
}

#endif
