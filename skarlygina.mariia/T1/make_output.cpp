#include "make_output.h"
#include <iomanip>
#include <iostream>
#include "shape.h"
#include "figure_array.h"

void makeOutputPosition(std::ostream& out, const Shape* figure)
{
  out << std::fixed;
  rectangle_t frame_rectangle = figure->getFrameRectangle();
  double framed_x1 = frame_rectangle.position.x - frame_rectangle.width / 2;
  double framed_y1 = frame_rectangle.position.y - frame_rectangle.height / 2;
  double framed_x2 = frame_rectangle.position.x + frame_rectangle.width / 2;
  double framed_y2 = frame_rectangle.position.y + frame_rectangle.height / 2;
  out << framed_x1 << " " << framed_y1 << " ";
  out << framed_x2 << " " << framed_y2;
}

void makeOutput(std::ostream& out, const Shape* const* array_figures, size_t size)
{
  if (size < 1)
  {
    throw std::invalid_argument("Invalid size of Shape array");
  }
  double sum = 0.0;
  for (size_t i = 0; i < size; i++)
  {
    sum += array_figures[i]->getArea();
  }
  out << std::fixed << std::setprecision(1) << sum;
  for (size_t i = 0; i < size; i++)
  {
    out << " ";
    makeOutputPosition(out, array_figures[i]);
  }
  out << "\n";
}
