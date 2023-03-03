#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <string>
#include "compositeShape.hpp"
#include "ellipse.hpp"
#include "base-types.hpp"
#include "shape.hpp"
#include"parallelogram.hpp"
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
    if (name == "ELLIPSE")
    {
      zasulsky::point_t center;
      double radiusVertical;
      double radiusHorizontal;
      std::cin >> center.x >> center.y;
      std::cin >> radiusVertical >> radiusHorizontal;
      if (!std::cin.good())
      {
        break;
      }
      zasulsky::Ellipse* ellipse = nullptr;
      try
      {
        ellipse = new zasulsky::Ellipse(center, radiusVertical, radiusHorizontal);
      }
      catch (const std::bad_alloc& e)
      {
        std::cout << "out of memory\n";
        return 1;
      }
      catch (const std::invalid_argument& e)
      {
        std::cout << e.what() << '\n';
        continue;
      }
      try
      {
        composite.push_back(ellipse);
      }
      catch (const std::bad_alloc& e)
      {
        delete ellipse;
        std::cout << "out of memory\n";
        return 1;
      }
    }
    else if (name == "PARALLELOGRAM")
    {
      zasulsky::point_t p1;
      zasulsky::point_t p2;
      zasulsky::point_t p3;
      std::cin >> p1.x >> p1.y;
      std::cin >> p2.x >> p2.y;
      std::cin >> p3.x >> p3.y;
      if (!std::cin.good())
      {
        break;
      }
      zasulsky::Parallelogram* parallelogram = nullptr;
      try
      {
        parallelogram = new zasulsky::Parallelogram(p1, p2, p3);
      }
      catch (const std::bad_alloc& e)
      {
        std::cout << "out of memory\n";
        return 1;
      }
      catch (const std::invalid_argument& e)
      {
        std::cout << e.what() << '\n';
        continue;
      }
      try
      {
        composite.push_back(parallelogram);
      }
      catch (const std::bad_alloc& e)
      {
        delete parallelogram;
        std::cout << "out of memory\n";
        return 1;
      }
    }
    else if (name == "RECTANGLE")
    {
      zasulsky::point_t p1;
      zasulsky::point_t p2;
      std::cin >> p1.x >> p1.y;
      std::cin >> p2.x >> p2.y;
      if (!std::cin.good())
      {
        break;
      }
      zasulsky::Rectangle* rectangle = nullptr;
      try
      {
        rectangle = new zasulsky::Rectangle(p1, p2);
      }
      catch (const std::bad_alloc& error)
      {
        std::cout << "out of memory\n";
        return 1;
      }
      catch (const std::invalid_argument& e)
      {
        std::cout << e.what() << '\n';
        continue;
      }
      try
      {
        composite.push_back(rectangle);
      }
      catch (const std::bad_alloc& e)
      {
        delete rectangle;
        std::cout << "out of memory\n";
        return 1;
      }
    }
    else if (name == "SCALE")
    {
      zasulsky::point_t scaleCenter;
      double k;
      std::cin >> scaleCenter.x >> scaleCenter.y;
      std::cin >> k;
      if (!std::cin.good())
      {
        break;
      }
      if (k <= 0.0)
      {
        std::cout << "coefficient is not correctly\n";
        continue;
      }
      try
      {
        zasulsky::outputComposite(std::cout, composite) << '\n';
        zasulsky::isoScale(composite, scaleCenter, k);
        hasScaled = true;
        zasulsky::outputComposite(std::cout, composite) << '\n';
      }
      catch(const std::runtime_error& e)
      {
        std::cout << e.what() << ' ';
        return 1;
      }
    }
  }
  if (!std::cin && !std::cin.eof())
  {
    std::cout << "input error\n";
    return 1;
  }
  if (!hasScaled)
  {
    std::cout << "hasn't scaled\n";
    return 1;
  }
}
