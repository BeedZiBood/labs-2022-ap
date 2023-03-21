#ifndef SPBSPU_LABS_2022_AAP_904_A_INPUT_SHAPES_H
#define SPBSPU_LABS_2022_AAP_904_A_INPUT_SHAPES_H
#include <istream>
#include "shape.h"
namespace dimkashelk
{
  Shape* inputRectangle(std::istream &in);
  Shape* inputRegular(std::istream &in);
  Shape* inputPolygon(std::istream &in);
  Shape* inputEllipse(std::istream &in);
}
#endif
