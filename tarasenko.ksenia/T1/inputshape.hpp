#ifndef INPUTSHAPE_HPP
#define INPUTSHAPE_HPP
#include <iostream>
#include "shape.hpp"

namespace tarasenko
{
  Shape * inputRectangle(std::istream & input);
  Shape * inputTriangle(std::istream & input);
  Shape * inputComplexquad(std::istream & input);
}
#endif
