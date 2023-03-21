#ifndef CREATESHAPES_HPP
#define CREATESHAPES_HPP
#include <istream>
#include <array>
#include <cstddef>
#include "shape.hpp"

void checkingInput(std::istream  &input);
double *inputInArr(std::istream &input, double *positions, size_t size);
Shape *createRectangle(std::istream &input);
Shape *createRing(std::istream &input);
Shape *createConcave(std::istream &input);
Shape *createDiamond(std::istream &input);
scale_t getScale(std::istream &input);

#endif
