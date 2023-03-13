#include <iostream>
#include "shape.h"
#include "rectangle.h"
#include "parallelogram.h"
#include "diamond.h"

int main()
{
  std::string figure;
  std::cin >> figure;
  if (figure == "RECTANGLE")
  {
    double x1 = 0.0;
    double x2 = 0.0;
    double y1 = 0.0;
    double y2 = 0.0;
    std::cin >> x1 >> y1 >> x2 >> y2;
    Rectangle * rectangle = new Rectangle({x1, y1}, {x2, y2});
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
  }
  return 0;
}
