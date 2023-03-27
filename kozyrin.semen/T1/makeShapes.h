#ifndef MAKESHAPES_H
#define MAKESHAPES_H
#include <iostream>
#include "complexquad.h"
#include "rectangle.h"
#include "ellipse.h"

namespace kozyrin {
  Shape* makeRectangle(std::istream& input);
  Shape* makeEllipse(std::istream& input);
  Shape* makeComplexquad(std::istream& input);
  void inputPoints(std::istream& input, double* arr, size_t size);
}

#endif
