#ifndef MAKESHAPES_HPP
#define MAKESHAPES_HPP

#include <istream>
#include "Shape.hpp"
#include "CompositeShape.hpp"

Shape *makeRectangle(std::istream &input);
Shape *makeEllipse(std::istream &input);
Shape *makeConcave(std::istream &input);
Shape *makeRing(std::istream &input);
scale_t getScale(std::istream &input);
void checkInput(std::istream &input);

#endif
