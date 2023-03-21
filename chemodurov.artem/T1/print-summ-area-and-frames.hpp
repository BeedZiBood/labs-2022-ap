#ifndef PRINT_SUMM_AREA_AND_FRAMES_HPP
#define PRINT_SUMM_AREA_AND_FRAMES_HPP
#include <iosfwd>
#include <cstddef>
#include "shape.hpp"
#include "composite-shape.hpp"

namespace chemodurov
{
  void printSummAreaAndFrames(std::ostream & out, const CompositeShape & comp, size_t shp_size);
}

#endif
