#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "Rectangle.h"
#include "ring.h"
#include "triangle.h"
#include "compositeShape.h"

void printShapes(const CompociteShape& cShape, char delimiter)
{
  std::cout << cShape.getArea();
  for (size_t i = 0; i < cShape.sizeArr(); i++)
  {
    std::cout << delimiter << cShape[i]->getFrameRect().center.x - cShape[i]->getFrameRect().width / 2;
    std::cout << delimiter << cShape[i]->getFrameRect().center.y - cShape[i]->getFrameRect().height / 2;
    std::cout << delimiter << cShape[i]->getFrameRect().center.x + cShape[i]->getFrameRect().width / 2;
    std::cout << delimiter << cShape[i]->getFrameRect().center.y + cShape[i]->getFrameRect().height / 2;
  }
}

int main()
{
  std::cout << std::setprecision(1) << std::fixed;
  CompociteShape cShape;
  bool invalidShape = false;
  bool isScaleCalled = false;
  bool invalidScale = false;
  bool invalidComposite = false;
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
      Shape* shape = nullptr;
      try
      {
        if (name == "RECTANGLE")
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
        else if (name == "TRIANGLE")
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
        else if (name == "RING")
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
      catch (const std::invalid_argument& e)
      {
        invalidShape = true;
      }
      catch (...)
      {
        invalidComposite = true;
      }
    }

    if (name == "SCALE")
    {
      isScaleCalled = true;
      double x = 0.0;
      double y = 0.0;
      std::cin >> x >> y;
      point_t point{ x, y };
      double k = 0.0;
      std::cin >> k;
      printShapes(cShape, ' ');
      std::cout << '\n';
      try
      {
        cShape.isoScale(point, k);
      }
      catch (...)
      {
        invalidScale = true;
      }
      printShapes(cShape, ' ');
      std::cout << '\n';
    }
  }

  if (!isScaleCalled)
  {
    std::cerr << "Scale was not called";
    return 1;
  }
  if (invalidShape)
  {
    std::cerr << "Invalid shape or shapes";
  }
  if (invalidScale)
  {
    std::cerr << "Invalid scaling";
    return 1;
  }
  if (invalidComposite)
  {
    std::cerr << "Invalid composite";
  }
  return 0;
}
