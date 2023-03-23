#include <iomanip>
#include <iostream>
#include <stdexcept>
#include "basetype.h"
#include "circle.h"
#include "compositeshape.h"
#include "rectangle.h"
#include "square.h"

int main()
{
  std::cout << std::setprecision(1) << std::fixed;
  bool use = false;
  chulkov::CompositeShape compositeShape;
  while (std::cin)
  {
    std::string name = "";
    std::cin >> name;
    if (!std::cin)
    {
      std::cerr << "Error input\n";
      return 1;
    }
    try
    {
      if (name == "RECTANGLE")
      {
        use = true;
        try
        {
          double x = 0.0;
          double y = 0.0;
          std::cin >> x >> y;
          chulkov::point_t a{x, y};
          std::cin >> x >> y;
          chulkov::point_t b{x, y};
          if (a.x > b.x || a.y > b.y)
          {
            throw std::logic_error("Bad scale");
          }
          if (!std::cin)
          {
            throw std::invalid_argument("invalid arguments");
          }
          try
          {
            chulkov::Rectangle* rect = new chulkov::Rectangle(a, b);
            compositeShape.pushBack(rect);
          }
          catch (const std::exception& e)
          {
            std::cerr << e.what() << "\n";
          }
        }
        catch (const std::logic_error& e)
        {
          std::cerr << e.what() << "\n";
        }
      }
      else if (name == "SQUARE")
      {
        use = true;
        try
        {
          double x = 0.0;
          double y = 0.0;
          double z = 0.0;
          std::cin >> x >> y >> z;
          if (!std::cin)
          {
            throw std::invalid_argument("invalid arguments");
          }
          try
          {
            chulkov::Square* square = new chulkov::Square(chulkov::point_t{x, y}, z);
            compositeShape.pushBack(square);
          }
          catch (const std::exception& e)
          {
            std::cerr << e.what() << "\n";
          }
        }
        catch (const std::logic_error& e)
        {
          std::cerr << e.what() << "\n";
        }
      }
      else if (name == "CIRCLE")
      {
        use = true;
        try
        {
          double x = 0.0;
          double y = 0.0;
          double r = 0.0;
          std::cin >> x >> y >> r;
          try
          {
            chulkov::Circle* circle = new chulkov::Circle({x, y}, r);
            compositeShape.pushBack(circle);
          }
          catch (const std::exception& e)
          {
            std::cerr << e.what() << "\n";
          }
        }
        catch (const std::exception& e)
        {
          std::cerr << e.what() << "\n";
        }
      }
    }
    catch (const std::invalid_argument& e)
    {
      std::cerr << e.what() << "\n";
    }
    if (name == "SCALE")
    {
      try
      {
        if (!use)
        {
          throw std::logic_error("Figure is not define");
        }
        double x = 0.0;
        double y = 0.0;
        std::cin >> x >> y;
        chulkov::point_t point{x, y};
        double k = 0.0;
        std::cin >> k;
        std::cout << (compositeShape.getArea());
        compositeShape.print();
        std::cout << "\n";
        compositeShape.isotropScale(point, k);
        std::cout << compositeShape.getArea();
        compositeShape.print();
        std::cout << "\n";
      }
      catch (const std::invalid_argument& e)
      {
        std::cerr << e.what() << "\n";
        return 1;
      }
      catch (const std::logic_error& e)
      {
        std::cerr << e.what() << "\n";
        return 1;
      }
      return 0;
    }
  }
  return 0;
}
