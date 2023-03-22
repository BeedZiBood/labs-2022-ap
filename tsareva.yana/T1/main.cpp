#include <iostream>
#include <cstddef>
#include <iomanip>
#include <golden_ratio.h>
#include "shape.h"
#include "rectangle.h"
#include "parallelogram.h"
#include "diamond.h"
#include "isotropic_scale.h"

void clearingMemory(tsareva::Shape ** pShape, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    delete pShape[i];
  }
  delete [] pShape;
}

tsareva::Shape ** extend(tsareva::Shape ** pShape, size_t old_size, size_t new_capacity)
{
  if (new_capacity < old_size)
  {
    throw std::invalid_argument("bruh");
  }
  tsareva::Shape ** extended = new tsareva::Shape*[new_capacity];
  for (size_t i = 0; i < old_size; i++)
  {
    extended[i] = pShape[i];
  }
  return extended;
}

tsareva::Shape ** addFigure(tsareva::Shape ** shapes, size_t & size, size_t & capacity, tsareva::Shape * figure)
{
  if (size == capacity)
  {
    tsareva::Shape ** new_shapes = extend(shapes, size, goldenRatio(capacity));
    capacity = goldenRatio(capacity);
    clearingMemory(shapes, size);
    shapes = new_shapes;
  }
  shapes[size] = figure;
  size++;
  return shapes;
}

int main()
{
  std::string figure;
  size_t size = 0;
  size_t capacity = 10;
  tsareva::Shape ** shapes = new tsareva::Shape*[capacity];
  bool isCorrectFigure = true;
  bool isScale = false;
  while (std::cin)
  {
    std::cin >> figure;
    if (!std::cin)
    {
      break;
    }
    if (figure == "RECTANGLE")
    {
      double p[4];
      for (size_t i = 1; i < 4; i++)
      {
        std::cin >> p[i];
      }
      try
      {
        tsareva::Rectangle * rectangle = new tsareva::Rectangle({p[0], p[1]}, {p[2], p[3]});
        shapes = addFigure(shapes, size, capacity, rectangle);
      }
      catch (...)
      {
        isCorrectFigure = false;
      }
    }
    else if (figure == "PARALLELOGRAM")
    {
      double p[6];
      for (size_t i = 1; i < 6; i++)
      {
        std::cin >> p[i];
      }
      try
      {
        tsareva::Parallelogram * parallelogram = new tsareva::Parallelogram({p[0], p[1]}, {p[2], p[3]}, {p[4], p[5]});
        shapes = addFigure(shapes, size, capacity, parallelogram);
      }
      catch (...)
      {
        isCorrectFigure = false;
      }
    }
    else if (figure == "DIAMOND")
    {
      double p[6];
      for (size_t i = 1; i < 6; i++)
      {
        std::cin >> p[i];
      }
      try
      {
        tsareva::Diamond * diamond = new tsareva::Diamond({p[0], p[1]}, {p[2], p[3]}, {p[4], p[5]});
        shapes = addFigure(shapes, size, capacity, diamond);
      }
      catch (...)
      {
        isCorrectFigure = false;
      }
    }
    else if (figure == "SCALE")
    {
      isScale = true;
      if (size == 0)
      {
        std::cerr << "No figure(sucker redo)";
        delete [] shapes;
        return 1;
      }
      double x1 = 0.0;
      double y1 = 0.0;
      double k = 0.0;
      std::cin >> x1 >> y1 >> k;
      if (k <= 0)
      {
        std::cerr << "Invalid coefficient(sucker redo)";
        clearingMemory(shapes, size);
        return 1;
      }
      double sum_area_figure = 0.0;
      for (size_t i = 0; i < size; i++)
      {
        sum_area_figure += shapes[i]->getArea();
      }
      std::cout << std::setprecision(1) << std::fixed << sum_area_figure;
      sum_area_figure = 0.0;
      for (size_t i = 0; i < size; i++)
      {
        tsareva::rectangle_t rectangle = shapes[i]->getFrameRectangle();
        std::cout << " " << rectangle.position.x - rectangle.width / 2 << " " << rectangle.position.y - rectangle.height / 2
                  << " " << rectangle.position.x + rectangle.width / 2 << " " << rectangle.position.y + rectangle.height / 2;
        isotropicScale(shapes[i], {x1, y1}, k);
        sum_area_figure += shapes[i]->getArea();
      }
      std::cout << "\n" << sum_area_figure;
      for (size_t i = 0; i < size; i++)
      {
        tsareva::rectangle_t rectangle = shapes[i]->getFrameRectangle();
        std::cout << " " << rectangle.position.x - rectangle.width / 2 << " " << rectangle.position.y - rectangle.height / 2
                  << " " << rectangle.position.x + rectangle.width / 2 << " " << rectangle.position.y + rectangle.height / 2;
      }
      std::cout << "\n";
      if (!isCorrectFigure)
      {
        std::cerr << "Invalid figure(sucker redo)";
      }
      clearingMemory(shapes, size);
      return 0;
    }
  }
  clearingMemory(shapes, size);
  if (!isScale)
  {
    std::cerr << "No scaling(sucker redo)";
    return 1;
  }
  return 0;
}
