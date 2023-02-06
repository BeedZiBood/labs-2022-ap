#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "Rectangle.h"
#include "ring.h"
#include "triangle.h"
#include "compositeShape.h"

int main()
{
  std::cout << std::setprecision(1);
  try
  {
    CompositeShape cShape;
    std::string type = "";
    for (std::cin >> type; std::cin; std::cin >> type)
    {
      std::cout << type << '\n';
      try
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
        else if (type == "RECTANGLE")
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
      }
      catch (const std::logic_error& e)
      {
        std::cout << e.what() << "\n";
      }
      try
      {
        if (type == "SCALE")
        {
          double x = 0;
          double y = 0;
          double k = 0;
          std::cin >> x >> y >> k;

          cShape.isoScale(point_t{ x, y }, k);
        }
      }
      catch (const std::logic_error& e)
      {
        std::cout << e.what() << "\n";
        return 1;
      }

      std::cout << cShape.getArea() << '\t';
      std::cout << cShape.getFrameRect().pos.x - cShape.getFrameRect().width / 2 << " ";
      std::cout << cShape.getFrameRect().pos.y - cShape.getFrameRect().height / 2 << " ";
      std::cout << cShape.getFrameRect().pos.x + cShape.getFrameRect().width / 2 << " ";
      std::cout << cShape.getFrameRect().pos.y + cShape.getFrameRect().height / 2 << "\n";

    }
  }
  catch (const std::exception& e)
  {
    std::cout << e.what() << '\n';
    return 1;
  }

  return 0;
}
