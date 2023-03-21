#include <iostream>
#include "shape.h"
#include "rectangle.h"
#include "ring.h"
#include "ellipse.h"
#include "make_output.h"
#include "figure_array.h"
#include "isotropic_scale.h"

int main()
{
  std::string figure = "";
  size_t size = 0;
  point_t point{};
  double coefficient = 0;
  bool isScale = false;
  bool isCommand = true;
  Shape** array_figures = new Shape*[size];
  do
  {
    Shape* shape = nullptr;
    try
    {
      std::cin >> figure;
      if (figure == "RECTANGLE")
      {
        double parameters[4]{};
        std::cin >> parameters[0] >> parameters[1] >> parameters[2] >> parameters[3];
        shape = new Rectangle({parameters[0], parameters[1]}, {parameters[2], parameters[3]});
        Shape** extend_array = FigureArray::extendArray(array_figures, shape, size);
        delete[] array_figures;
        array_figures = extend_array;
        size++;
      }
      if (figure == "RING")
      {
        double parameters[4]{};
        std::cin >> parameters[0] >> parameters[1] >> parameters[2] >> parameters[3];
        shape = new Ring({parameters[0], parameters[1]}, parameters[3], parameters[2]);
        Shape** extend_array = FigureArray::extendArray(array_figures, shape, size);
        delete[] array_figures;
        array_figures = extend_array;
        size++;
      }
      if (figure == "ELLIPSE")
      {
        double parameters[4]{};
        std::cin >> parameters[0] >> parameters[1] >> parameters[2] >> parameters[3];
        shape = new Ellipse({parameters[0], parameters[1]}, parameters[2], parameters[3]);
        Shape** extend_array = FigureArray::extendArray(array_figures, shape, size);
        delete[] array_figures;
        array_figures = extend_array;
        size++;
      }
      if (figure == "SCALE")
      {
        isScale = true;
        std::cin >> point.x >> point.y >> coefficient;
        if (coefficient <= 0)
        {
          std::cerr << "Error: coefficient could not be under zero\n";
          FigureArray::deleteArray(size, array_figures);
          return 2;
        }
        break;
      }
    }
    catch (const std::invalid_argument& e)
    {
      std::cerr << e.what() << "\n";
      delete shape;
      isCommand = false;
      continue;
    }
    catch (...)
    {
      std::cerr << "Error: wrong parameters of the point, coefficient\n";
      FigureArray::deleteArray(size, array_figures);
      return 2;
    }
  }
  while (std::cin);

  if (size > 0 && isScale)
  {
    makeOutput(std::cout, array_figures, size);
    for (size_t i = 0; i < size; i++)
    {
      makeIsotropicScaling(array_figures[i], point, coefficient);
    }
    makeOutput(std::cout, array_figures, size);
    if (!isCommand)
    {
      std::cerr << "Some figures are not correct\n";
    }
  }
  else if (!isScale)
  {
    FigureArray::deleteArray(size, array_figures);
    std::cerr << "Error: the final figure could be SCALE and size bigger than zero";
    return 2;
  }
  else if (size < 1)
  {
    FigureArray::deleteArray(size, array_figures);
    std::cerr << "Error: the final figure could be SCALE and size bigger than zero";
    return 2;
  }
  FigureArray::deleteArray(size, array_figures);
  return 0;
}
