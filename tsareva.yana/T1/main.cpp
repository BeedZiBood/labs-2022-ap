#include <iostream>
#include <cstddef>
#include "shape.h"
#include "rectangle.h"
#include "parallelogram.h"
#include "diamond.h"

int main()
{
  std::string figure;
  std::cin >> figure;
  size_t size = 0;
  size_t capacity = 10;
  Shape ** shapes = new Shape*[capacity];
  if (figure == "RECTANGLE")
  {
    double x1 = 0.0;
    double x2 = 0.0;
    double y1 = 0.0;
    double y2 = 0.0;
    std::cin >> x1 >> y1 >> x2 >> y2;
    Rectangle * rectangle = new Rectangle({x1, y1}, {x2, y2});
    shapes[size] = rectangle;
    size++;
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
    Parallelogram * parallelogram = new Parallelogram({x1, y1}, {x2, y2}, {x3, y3});
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
    Diamond * diamond = new Diamond({x1, y1}, {x2, y2}, {x3, y3});
    shapes[size] = diamond;
    size++;
  }
  return 0;
}
