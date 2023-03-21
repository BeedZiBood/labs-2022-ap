#include <iostream>
#include <string>
#include <iomanip>
#include "square.hpp"
#include "rectangle.hpp"
#include "parallelogram.hpp"
#include "iso-scale.hpp"
#include "print-summ-area-and-frames.hpp"
#include "make-polygon-from-string.hpp"
#include "is-repeating-points-in-array.hpp"
#include "check-command-in-string.hpp"
#include "composite-shape.hpp"

int main()
{
  std::string line;
  size_t shp_cap = 10;
  chemodurov::CompositeShape shapes(shp_cap);
  chemodurov::point_t iso_scale_center;
  double iso_scale_coeff = 0;
  const size_t polygon_size = 7;
  const size_t square_size = 6;
  const size_t rectangle_size = 9;
  const size_t parallelogram_size = 13;
  const size_t scale_size = 5;

  do
  {
    std::getline(std::cin, line);
    if (chemodurov::checkCommand(line, "POLYGON"))
    {
      chemodurov::point_t * arr = nullptr;
      size_t arr_size = 0;
      chemodurov::Shape * polygon = nullptr;
      try
      {
        arr = chemodurov::getArrayOfPoints(line, polygon_size, arr_size);
        polygon = new chemodurov::Polygon(arr, arr_size);
      }
      catch (const std::invalid_argument & e)
      {
        std::cerr << e.what() << "\n";
        delete [] arr;
        continue;
      }
      catch (...)
      {
        std::cerr << "Error...\n";
        delete[] arr;
        return 1;
      }
      shapes.push_back(polygon);
      continue;
    }

    if (chemodurov::checkCommand(line, "SQUARE"))
    {
      std::string::size_type size1 = square_size;
      std::string::size_type size2 = 0;
      double x = std::stod(line.substr(size1), std::addressof(size2));
      size2 += size1;
      double y = std::stod(line.substr(size2), std::addressof(size1));
      size1 += size2;
      chemodurov::point_t temp{x, y};
      double length = std::stod(line.substr(size1));
      try
      {
        shapes.push_back(new chemodurov::Square(temp, length));
      }
      catch (const std::invalid_argument & e)
      {
        std::cerr << e.what() << "\n";
        continue;
      }
      continue;
    }

    if (chemodurov::checkCommand(line, "RECTANGLE"))
    {
      std::string::size_type size1 = rectangle_size;
      std::string::size_type size2 = 0;
      double x = std::stod(line.substr(size1), std::addressof(size2));
      size2 += size1;
      double y = std::stod(line.substr(size2), std::addressof(size1));
      size1 += size2;
      chemodurov::point_t left_down{x, y};
      x = std::stod(line.substr(size1), std::addressof(size2));
      size2 += size1;
      y = std::stod(line.substr(size2), std::addressof(size1));
      chemodurov::point_t right_up{x, y};
      try
      {
        shapes.push_back(new chemodurov::Rectangle(left_down, right_up));
      }
      catch (const std::invalid_argument & e)
      {
        std::cerr << e.what() << "\n";
        continue;
      }
      continue;
    }

    if (chemodurov::checkCommand(line, "PARALLELOGRAM"))
    {
      std::string::size_type size1 = parallelogram_size;
      std::string::size_type size2 = 0;
      double x = std::stod(line.substr(size1), std::addressof(size2));
      size2 += size1;
      double y = std::stod(line.substr(size2), std::addressof(size1));
      size1 += size2;
      chemodurov::point_t fst{x, y};
      x = std::stod(line.substr(size1), std::addressof(size2));
      size2 += size1;
      y = std::stod(line.substr(size2), std::addressof(size1));
      size1 += size2;
      chemodurov::point_t sec{x, y};
      x = std::stod(line.substr(size1), std::addressof(size2));
      size2 += size1;
      y = std::stod(line.substr(size2), std::addressof(size1));
      size1 += size2;
      chemodurov::point_t trd{x, y};
      try
      {
        shapes.push_back(new chemodurov::Parallelogram(fst, sec, trd));
      }
      catch (const std::invalid_argument & e)
      {
        std::cerr << e.what() << "\n";
        continue;
      }
      continue;
    }

    if (chemodurov::checkCommand(line, "SCALE"))
    {
      std::string::size_type size1 = scale_size;
      std::string::size_type size2 = 0;
      double x = std::stod(line.substr(size1), std::addressof(size2));
      size2 += size1;
      double y = std::stod(line.substr(size2), std::addressof(size1));
      size1 += size2;
      iso_scale_coeff = std::stod(line.substr(size1));
      iso_scale_center = {x, y};
      break;
    }
  }
  while (std::cin);

  if (!std::cin || !shapes.size() || iso_scale_coeff <= 0)
  {
    std::cerr << "Error...\n";
    return 1;
  }
  chemodurov::printSummAreaAndFrames(std::cout << std::fixed << std::setprecision(1),  shapes, shapes.size());
  std::cout << "\n";

  for (size_t i = 0; i < shapes.size(); ++i)
  {
    isoScale(shapes[i], iso_scale_center, iso_scale_coeff);
  }
  chemodurov::printSummAreaAndFrames(std::cout, shapes, shapes.size());
  std::cout << "\n";
  return 0;
}
