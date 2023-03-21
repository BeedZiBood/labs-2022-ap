#include <iostream>
#include <stdexcept>
#include <cstddef>
#include <iomanip>
#include "compositeshape.h"
#include "isotropic_scaling.h"
#include "base_functions.h"
#include "input_shapes.h"
double getArea(const dimkashelk::CompositeShape &compositeShape)
{
  double sum_area = 0.0;
  for (size_t i = 0; i < compositeShape.size(); i++)
  {
    sum_area += compositeShape[i]->getArea();
  }
  return sum_area;
}
std::ostream& outputShapes(std::ostream &out, const dimkashelk::CompositeShape &compositeShape)
{
  namespace dks = dimkashelk;
  out << std::setprecision(1) << std::fixed << getArea(compositeShape);
  for (size_t i = 0; i < compositeShape.size(); i++)
  {
    dks::rectangle_t rect = compositeShape[i]->getFrameRect();
    dks::point_t left_down = getLeftDownPoint(rect);
    dks::point_t right_up = getRightUpPoint(rect);
    out << " " << left_down.x << " " << left_down.y << " " << right_up.x << " " << right_up.y;
  }
  return out;
}
int main()
{
  namespace dks = dimkashelk;
  std::string line = "";
  bool contains_errors_with_shapes = false;
  bool call_scale = false;
  dks::CompositeShape compositeShape;
  while (std::cin)
  {
    std::string name = "";
    std::cin >> name;
    if (!std::cin)
    {
      break;
    }
    if (name == "RECTANGLE")
    {
      try
      {
        dks::Shape *shape = dks::inputRectangle(std::cin);
        compositeShape.push_back(shape);
      }
      catch (const std::logic_error &e)
      {
        contains_errors_with_shapes = true;
      }
    }
    else if (name == "REGULAR")
    {
      try
      {
        dks::Shape *shape = dks::inputRegular(std::cin);
        compositeShape.push_back(shape);
      }
      catch (const std::logic_error &e)
      {
        contains_errors_with_shapes = true;
      }
    }
    else if (name == "POLYGON")
    {
      try
      {
        dks::Shape *shape = dks::inputPolygon(std::cin);
        compositeShape.push_back(shape);
      }
      catch (...)
      {
        contains_errors_with_shapes = true;
      }
      std::cin.clear();
    }
    else if (name == "ELLIPSE")
    {
      try
      {
        dks::Shape *shape = dks::inputEllipse(std::cin);
        compositeShape.push_back(shape);
      }
      catch (...)
      {
        contains_errors_with_shapes = true;
      }
    }
    else if (name == "SCALE")
    {
      call_scale = true;
      double x = 0.0;
      double y = 0.0;
      std::cin >> x >> y;
      dks::point_t point{x, y};
      double k = 0.0;
      std::cin >> k;
      outputShapes(std::cout, compositeShape) << "\n";
      try
      {
        compositeShape.isotropicScaling(point, k);
      }
      catch (const std::logic_error &e)
      {
        std::cerr << e.what();
        return 1;
      }
      outputShapes(std::cout, compositeShape) << "\n";
      if (contains_errors_with_shapes)
      {
        contains_errors_with_shapes = false;
        std::cerr << "Contains errors in description of figures";
      }
    }
    else
    {
      double coord = 0.0;
      while (std::cin)
      {
        std::cin >> coord;
      }
      std::cin.clear();
    }
  }
  if (!call_scale)
  {
    std::cerr << "Not scaled shapes";
    return 1;
  }
  return 0;
}
