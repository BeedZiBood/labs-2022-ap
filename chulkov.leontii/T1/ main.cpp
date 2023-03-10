#include <iostream>
#include <iomanip>
#include "shape.h"
#include "basetype.h"
#include "square.h"
#include "circle.h"
#include "rectangle.h"
#include "compositeShape.h"
#include "print.h"

int main()
{
  std::cout << std::setprecision(1) << std::fixed;
  CompositeShape compositeShape;
  while (std::cin)
  {
    std::string name = "";
    std::cin >> name;
    if (!std::cin)
    {
      std::cerr << "Error input\n";
      return 1;
    }
    if (name == "RECTANGLE" || name == "SQUARE" || name == "CIRCLE")
    {
      try
      {
        if (name == "RECTANGLE")
        {
          try
          {
            double x = 0.0;
            double y = 0.0;
            std::cin >> x >>y;
            point_t a{x, y};
            std::cin >> x >> y;
            point_t b{x, y};
            if (!std::cin)
            {
              throw std::invalid_argument("invalid arguments");
            }
            Rectangle* rect = new Rectangle(a, b);
            compositeShape.pushBack(rect);
          }
          catch (const std::logic_error& e)
          {
            std::cerr << e.what() << "\n";
          }
        }
      }
    }
  }
  return 0;
}
