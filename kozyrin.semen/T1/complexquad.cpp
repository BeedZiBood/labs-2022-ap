#include "complexquad.h"
#include <cstddef>

Complexquad::Complexquad(point_t* pointArr)
{
  for (size_t i = 0; i < 4; ++i) {
    pointArr_[i] = pointArr[i];
  }
}

double Complexquad::getArea() const
{}