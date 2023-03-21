#ifndef FIGURE_ARRAY_H
#define FIGURE_ARRAY_H
#include "shape.h"
#include <cstddef>
namespace FigureArray
{
  void deleteArray(size_t size, const Shape* const* array_figures);
  Shape** extendArray(Shape** array_figure, Shape* figure, size_t size);
}
#endif
