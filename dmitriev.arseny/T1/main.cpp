#include <iostream>
#include <stdexcept>
#include "Rectangle.h"
#include "ring.h"
#include "triangle.h"
#include "compositeShape.h"

int main()
{
  std::cout << std::fixed;
  try
  {
    CompositeShape cShape;
    std::string type = "";
    for (std::cin >> type; std::cin; std::cin >> type)
    {
      if (type == "TRIANGLE")
      {
        double x = 0;
        double y = 0;
        std::cin >> x >> y;
        point_t a{ x, y };

        std::cin >> x >> y;
        point_t b{ x, y };

        std::cin >> x >> y;
        point_t c{ x, y };

        Triangle tri{ a, b, c };
        Shape* shape = tri.clone();

        cShape.push_back(shape);
      }
      else if (type == "RECNANGLE")
      {
        double x = 0;
        double y = 0;

        std::cin >> x >> y;
        point_t a{ x, y };

        std::cin >> x >> y;
        point_t b{ x, y };

        Rectangle rec{ a, b };
        Shape* shape = rec.clone();

        cShape.push_back(shape);
      }
      else if (type == "RING")
      {
        double x = 0;
        double y = 0;

        std::cin >> x >> y;
        point_t a{ x, y };
        std::cin >> x >> y;

        Ring rin{ a, x, y };
        Shape* shape = rin.clone();

        cShape.push_back(shape);
      }
      else if (type == "SCALE")
      {
        double x = 0;
        double y = 0;
        double k = 0;
        std::cin >> x >> y >> k;

        cShape.move(x, y);
        cShape.scale(k);
      }
    }
    std::cout << cShape.getArea() << '\n';

  }
  catch (const std::exception& e)
  {
    std::cout << e.what() << '\n';
  }

  return 0;
}
