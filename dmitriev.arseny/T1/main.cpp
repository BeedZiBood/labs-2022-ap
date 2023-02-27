#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "rectangle.h"
#include "ring.h"
#include "triangle.h"
#include "compositeShape.h"

int main()
{
  std::cout << std::setprecision(1) << std::fixed;

  CompositeShape cShape;
  bool isScaleCalled = false;

  while (std::cin)
  {
    std::string name = "";
    std::cin >> name;
    if (!std::cin)
    {
      break;
    }
    if (name == "RECTANGLE" || name == "TRIANGLE" || name == "RING")
    {
      try
      {
        if (name == "RECTANGLE")
        {
          double x = 0;
          double y = 0;

          std::cin >> x >> y;
          if (!std::cin)
          {
            throw std::invalid_argument("invalid_argument");
          }
          point_t a{x, y};

          std::cin >> x >> y;
          if (!std::cin)
          {
            throw std::invalid_argument("invalid_argument");
          }
          point_t b{x, y};

          Rectangle rec{a, b};
          Shape* shape = rec.clone();

          cShape.pushBack(shape);
        }
        else if (name == "TRIANGLE")
        {
          double x = 0;
          double y = 0;

          std::cin >> x >> y;
          if (!std::cin)
          {
            throw std::invalid_argument("invalid_argument");
          }
          point_t a{x, y};

          std::cin >> x >> y;
          if (!std::cin)
          {
            throw std::invalid_argument("invalid_argument");
          }
          point_t b{x, y};

          std::cin >> x >> y;
          if (!std::cin)
          {
            throw std::invalid_argument("invalid_argument");
          }
          point_t c{x, y};

          Triangle tri{a, b, c};
          Shape* shape = tri.clone();

          cShape.pushBack(shape);
        }
        else if (name == "RING")
        {
          double x = 0.0;
          double y = 0.0;

          std::cin >> x >> y;
          if (!std::cin)
          {
            throw std::invalid_argument("invalid_argument");
          }
          point_t a{x, y};
          std::cin >> x >> y;
          if (!std::cin)
          {
            throw std::invalid_argument("invalid_argument");
          }

          Ring rin{a, x, y};
          Shape* shape = rin.clone();

          cShape.pushBack(shape);
        }
      }
      catch (const std::invalid_argument& e)
      {
        std::cerr << "Invalid shape or shapes";
      }
      catch (const std::bad_alloc& e)
      {
        std::cerr << "Invalid composite";
      }
    }

    if (name == "SCALE")
    {
      isScaleCalled = true;
      double x = 0.0;
      double y = 0.0;

      std::cin >> x >> y;
      point_t point{x, y};

      double k = 0.0;

      std::cin >> k;
      cShape.printInfo(std::cout, ' ');
      std::cout << '\n';
      try
      {
        cShape.isoScale(point, k);
      }
      catch (const std::exception& e)
      {
        std::cerr << "Invalid scaling";
        return 1;
      }

      cShape.printInfo(std::cout, ' ');
      std::cout << '\n';
    }
  }

  if (!isScaleCalled)
  {
    std::cerr << "Scale was not called";
    return 1;
  }

  return 0;
}
