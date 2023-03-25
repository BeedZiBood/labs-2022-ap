#ifndef WORKWITHARRAY_H
#define WORKWITHARRAY_H
#include <cstddef>
#include "shape.h"
Shape **expandArray(Shape **shapes, size_t &capacity);
void deleteArray(Shape **shapes, size_t capacity);
#endif
