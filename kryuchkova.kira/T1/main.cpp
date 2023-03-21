#include <iostream>
#include "shape.h"
#include "base_types.h"
#include "circle.h"
#include "square.h"
#include "rectangle.h"
#include "composite_shape.h"

void printShapes(const kryuchkova::CompositeShape &compositeShape, char delimiter)
{
  std::cout << compositeShape.getArea();
  for (size_t i = 0; i < compositeShape.size(); i++)
  {
    std::cout << delimiter << *compositeShape.at(i);
  }
}

int main()
{
  std::cout << std::setprecision(1) << std::fixed;
  kryuchkova::CompositeShape compositeShape;
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

    if (name == "RECTANGLE" || name == "SQUARE" || name == "CIRCLE")
    {
      kryuchkova::Shape *shape = nullptr;
      try
      {
        if (name == "RECTANGLE")
        {
          shape = kryuchkova::inputRectangle(std::cin);
          compositeShape.push_back(shape);
        }
        else if (name == "SQUARE")
        {
          shape = kryuchkova::inputSquare(std::cin);
          compositeShape.push_back(shape);
        }
        else if (name == "CIRCLE")
        {
          shape = kryuchkova::inputCircle(std::cin);
          compositeShape.push_back(shape);
        }
      }
      catch (const std::invalid_argument &e)
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
      kryuchkova::point_t point{x, y};
      double k = 0.0;
      std::cin >> k;
      printShapes(compositeShape, ' ');
      std::cout << '\n';
      try
      {
        compositeShape.isoScale(point, k);
      }
      catch (...)
      {
        invalidScale = true;
      }
      printShapes(compositeShape, ' ');
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
