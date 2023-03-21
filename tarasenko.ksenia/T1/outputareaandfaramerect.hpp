#ifndef OUTPUTAREAANDFRAME_HPP
#define OUTPUTAREAANDFRAME_HPP
#include <iostream>
#include <cstddef>
#include "compositeshape.hpp"
namespace tarasenko
{
  void outputArea(std::ostream & output, CompositeShape & c_shp);
  void outputFrameRect(std::ostream & output, CompositeShape & c_shp);
  void outputAreaAndFrameRect(std::ostream & output, CompositeShape & c_shp);
};
#endif
