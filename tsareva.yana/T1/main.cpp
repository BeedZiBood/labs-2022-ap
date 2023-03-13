#include <iostream>
#include <cstddef>
#include "shape.h"
#include "rectangle.h"
#include "parallelogram.h"
#include "diamond.h"
#include "isotropic_scale.h"

int main()
{
  std::string figure;
  size_t size = 0;
  size_t capacity = 10;
  Shape ** shapes = new Shape*[capacity];
  bool isCorrectFigure = true;
  while (std::cin)
  {
    std::cin >> figure;
    if (figure == "RECTANGLE")
    {
      double x1 = 0.0;
      double x2 = 0.0;
      double y1 = 0.0;
      double y2 = 0.0;
      std::cin >> x1 >> y1 >> x2 >> y2;
      try
      {
        Rectangle *rectangle = new Rectangle({x1, y1}, {x2, y2});
        shapes[size] = rectangle;
        size++;
      }
      catch (...)
      {
        isCorrectFigure = false;
      }
    }
    else if (figure == "PARALLELOGRAM")
    {
      double x1 = 0.0;
      double x2 = 0.0;
      double y1 = 0.0;
      double y2 = 0.0;
      double x3 = 0.0;
      double y3 = 0.0;
      std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
      Parallelogram *parallelogram = new Parallelogram({x1, y1}, {x2, y2}, {x3, y3});
      shapes[size] = parallelogram;
      size++;
    }
    else if (figure == "DIAMOND")
    {
      double x1 = 0.0;
      double x2 = 0.0;
      double y1 = 0.0;
      double y2 = 0.0;
      double x3 = 0.0;
      double y3 = 0.0;
      std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
      Diamond *diamond = new Diamond({x1, y1}, {x2, y2}, {x3, y3});
      shapes[size] = diamond;
      size++;
    }
    else if (figure == "SCALE")
    {
      double x1 = 0.0;
      double y1 = 0.0;
      double k = 0.0;
      std::cin >> x1 >> y1 >> k;
      double sum_area_figure = 0.0;
      for (size_t i = 0; i < size; i++)
      {
        sum_area_figure += shapes[i]->getArea();
      }
      std::cout << sum_area_figure;
      sum_area_figure = 0.0;
      for (size_t i = 0; i < size; i++)
      {
        rectangle_t rectangle = shapes[i]->getFrameRectangle();
        std::cout << " " << rectangle.position.x - rectangle.width / 2 << " " << rectangle.position.y - rectangle.height / 2
                  << " " << rectangle.position.x + rectangle.width / 2 << " " << rectangle.position.y + rectangle.height / 2;
        isotropicScale(shapes[i], {x1, y1}, k);
        sum_area_figure += shapes[i]->getArea();
      }
      std::cout << "\n" << sum_area_figure;
      for (size_t i = 0; i < size; i++)
      {
        rectangle_t rectangle = shapes[i]->getFrameRectangle();
        std::cout << " " << rectangle.position.x - rectangle.width / 2 << " " << rectangle.position.y - rectangle.height / 2
                  << " " << rectangle.position.x + rectangle.width / 2 << " " << rectangle.position.y + rectangle.height / 2;
      }
    }
  }
  return 0;
}
