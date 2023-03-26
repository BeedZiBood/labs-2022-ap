#include "figure_array.h"

void FigureArray::deleteArray(size_t size, const Shape* const* array_figures)
{
  if (size > 0)
  {
    for (size_t i = 0; i < size; i++)
    {
      delete array_figures[i];
    }
  }
  delete[] array_figures;
}

Shape** FigureArray::extendArray(Shape** array_figure, Shape* figure, size_t size)
{
  size_t capacity = size + 1;
  Shape** array_extended = new Shape*[capacity];
  if (size > 0)
  {
    for (size_t i = 0; i < size; i++)
    {
      array_extended[i] = array_figure[i];
    }
  }
  array_extended[capacity - 1] = figure;
  return array_extended;
}
