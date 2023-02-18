#include <iostream>
#include <stdexcept>
#include "rectangle.hpp"
#include "compositeshape.hpp"
#include "inputshape.hpp"
#include "isoscale.hpp"
#include "outputareaandfaramerect.hpp"

int main()
{
  bool errors = false;
  bool scale_was = false;
  tarasenko::CompositeShape compositeShape;
  tarasenko::Shape * shape = nullptr;
  while (std::cin)
  {
    std::string name = "";
    std::cin >> name;
    if (!std::cin)
    {
      std::cerr << "Error in name\n";
      break;
    }
    try
    {
      if (name == "RECTANGLE")
      {
        shape = tarasenko::inputRectangle(std::cin);
        compositeShape.push_back(shape);
        shape = nullptr;
      }
      else if (name == "TRIANGLE")
      {
        shape = tarasenko::inputTriangle(std::cin);
        compositeShape.push_back(shape);
        shape = nullptr;
      }
      else if (name == "COMPLEXQUAD")
      {
        shape = tarasenko::inputComplexquad(std::cin);
        compositeShape.push_back(shape);
        shape = nullptr;
      }
      else if (name == "SCALE")
      {
        scale_was = true;
        double x = 0.0;
        double y = 0.0;
        double k = 0.0;
        std::cin >> x >> y >> k;
        if (!std::cin)
        {
          std::cerr << "Error\n";
        }
        tarasenko::point_t center_scale{x, y};
        tarasenko::outputAreaAndFrameRect(std::cout, compositeShape);
        std::cout << "\n";
        for (size_t i = 0; i < compositeShape.size(); i++)
        {
          isoScale(compositeShape[i], center_scale, k);
        }
        tarasenko::outputAreaAndFrameRect(std::cout, compositeShape);
        std::cout << "\n";
        break;
      }
      else
      {
        double skip = 0.0;
        while (std::cin)
        {
          std::cin >> skip;
        }
        std::cin.clear();
      }
    }
    catch (const std::invalid_argument & e)
    {
      delete shape;
      errors = true;
    }
    catch (const std::logic_error & e)
    {
      delete shape;
      std::cerr << e.what();
      return 1;
    }
  }
  if (errors)
  {
    std::cerr << "Errors in shapes\n";
  }
  if (!compositeShape.size())
  {
    std::cerr << "The shape was not called\n";
    return 1;
  }
  if (!scale_was)
  {
    std::cerr << "The SCALE was not called\n";
    return 1;
  }
}
