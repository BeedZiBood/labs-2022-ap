#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <string>
#include "compositeShape.hpp"
#include "ellipse.hpp"
#include "base-types.hpp"
#include "shape.hpp"
#include "parallelogram.hpp"
#include "rectangle.hpp"

int main()
{
  zasulsky::CompositeShape composite(10);
  bool hasScaled = false;
  std::cout << std::setprecision(1) << std::fixed;
  while (std::cin.good())
  {
    std::string name;
    std::cin >> name;
    if (!std::cin.good())
    {
      break;
    }
    zasulsky::Shape* shp = nullptr;
    try
    {
      if (name == "ELLIPSE")
      {
        zasulsky::point_t center{0.0, 0.0};
        double radiusVertical = 0.0;
        double radiusHorizontal = 0.0;
        std::cin >> center.x >> center.y;
        std::cin >> radiusVertical >> radiusHorizontal;
        if (!std::cin.good())
        {
          break;
        }
        shp = new zasulsky::Ellipse(center, radiusVertical, radiusHorizontal);
      }
      else if (name == "PARALLELOGRAM")
      {
        zasulsky::point_t p1{0.0, 0.0};
        zasulsky::point_t p2{0.0, 0.0};
        zasulsky::point_t p3{0.0, 0.0};
        std::cin >> p1.x >> p1.y;
        std::cin >> p2.x >> p2.y;
        std::cin >> p3.x >> p3.y;
        if (!std::cin.good())
        {
          break;
        }
        shp = new zasulsky::Parallelogram(p1, p2, p3);
      }
      else if (name == "RECTANGLE")
      {
        zasulsky::point_t p1{0.0, 0.0};
        zasulsky::point_t p2{0.0, 0.0};
        std::cin >> p1.x >> p1.y;
        std::cin >> p2.x >> p2.y;
        if (!std::cin.good())
        {
          break;
        }
        shp = new zasulsky::Rectangle(p1, p2);
      }
      else if (name == "SCALE")
      {
        zasulsky::point_t scaleCenter{0.0, 0.0};
        double k = 0.0;
        std::cin >> scaleCenter.x >> scaleCenter.y;
        std::cin >> k;
        if (!std::cin.good())
        {
          break;
        }
        if (k <= 0.0)
        {
          std::cerr << "coefficient is not correctly\n";
          continue;
        }
        zasulsky::outputComposite(std::cout, composite) << '\n';
        zasulsky::isoScale(composite, scaleCenter, k);
        hasScaled = true;
        zasulsky::outputComposite(std::cout, composite) << '\n';
      }
    }
    catch (const std::bad_alloc& error)
    {
      std::cerr << "out of memory\n";
      return 1;
    }
    catch (const std::invalid_argument& e)
    {
      std::cerr << e.what() << '\n';
      continue;
    }
    catch (const std::runtime_error& e)
    {
      std::cerr << e.what() << '\n';
      return 1;
    }
    try
    {
      if (shp != nullptr)
      {
        composite.push_back(shp);
      }
    }
    catch (const std::bad_alloc& e)
    {
      delete shp;
      std::cerr << "out of memory\n";
      return 1;
    }
  }
  if (!std::cin && !std::cin.eof())
  {
    std::cerr << "input error\n";
    return 1;
  }
  if (!hasScaled)
  {
    std::cerr << "hasn't scaled\n";
    return 1;
  }
}
