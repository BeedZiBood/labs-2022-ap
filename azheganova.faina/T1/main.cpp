#include <iostream>
#include <string>
#include <cstddef>
#include <iomanip>
#include <stdexcept>
#include "inputrectangle.h"
#include "isoscale.h"
#include "compositeshape.h"
#include "inputtriangle.h"
#include "inputcomplexquad.h"

void printLeftDownAndRightUp(std::ostream & output, const rectangle_t & rectangle)
  {
    point_t point1{rectangle.pos.x - 0.5 * rectangle.width, rectangle.pos.y - 0.5 * rectangle.height};
    point_t point2{rectangle.pos.x + 0.5 * rectangle.width, rectangle.pos.y + 0.5 * rectangle.height};
    output << point1.x << ' ' << point1.y << ' '<< point2.x << ' ' << point2.y;
  }

void printAreaAndFrames(std::ostream & out, const CompositeShape & comp, size_t shp_size)
{
  if (!shp_size)
  {
    throw std::invalid_argument("Invalid size of Shape array");
  }
  double summ_area = 0.0;
  for (size_t i = 0; i < shp_size; ++i)
  {
    summ_area += comp[i]->getArea();
  }
  out << summ_area;
  for (size_t i = 0; i < shp_size; ++i)
  {
    printLeftDownAndRightUp(out << ' ', comp[i]->getFrameRect());
  }
}

int main()
{
  std::string line;
  size_t cap = 10;
  double scalek;
  point_t scalecenter = {0, 0};
  CompositeShape rhs(cap);
  while(std::cin)
  {
    std::string name = "";
    std::cin >> name;
    if (name == "RECTANGLE")
    {
      try
      {
        Shape *shape = inputRectangle(std::cin);
        rhs.push_back(shape);
      }
      catch(const std::logic_error &e)
      {
        std::cerr << e.what() << "\n";
        continue;
      }
    }
    if (name == "TRIANGLE")
    {
      try
      {
        Shape *shape = inputTriangle(std::cin);
        rhs.push_back(shape);
      }
      catch(const std::logic_error &e)
      {
        std::cerr << e.what() << "\n";
        continue;
      }
    }
    if (name == "COMPLEXQUAD")
    {
      try
      {
      Shape *shape = inputComplexquad(std::cin);
      rhs.push_back(shape);
      }
      catch(const std::logic_error &e)
      {
        std::cerr << e.what() << "\n";
        continue;
      }
    }
    if (name == "SCALE")
    {
      double x = 0.0;
      double y = 0.0;
      double k = 0.0;
      std::cin >> x >> y >> k;
      if (k <= 0)
      {
        std::cout << "incorrect value";
      }
      point_t scalecenter = {x, y};
    }
  }
  if (!std::cin)
  {
    std::cout << "error";
  }
  if (scalek <= 0)
  {
    std::cout << "error";
  }
  printAreaAndFrames(std::cout << std::fixed << std::setprecision(1),  rhs, rhs.size());
  std::cout << "\n";
  for (size_t i = 0; i < rhs.size(); ++i)
  {
    isoScale(rhs[i], scalecenter, scalek);
  }
  printAreaAndFrames(std::cout, rhs, rhs.size());
  std::cout << "\n";
}
