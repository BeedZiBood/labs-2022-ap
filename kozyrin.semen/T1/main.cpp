#include <iostream>
#include "makeShapes.h"
#include <iomanip>

void output(std::ostream& outStream, std::istream& inStream, Shape** arr, size_t size)
{
  double x, y;
  inStream >> x;
  inStream >> y;
  point_t point{x, y};
  double k = 0;
  inStream >> k;

  double area = 0;
  for (size_t i = 0; i < size; ++i) {
    area += arr[i]->getArea();
  }
  outStream << std::setprecision(1) << std::fixed << area << ' ';
  rectangle_t rect = {0, 0, 0, 0};
  for (size_t i = 0; i < size; ++i) {
    rect = arr[i]->getFrameRect();
    outStream << rect.pos.x - rect.width / 2 << ' ' << rect.pos.y - rect.height / 2 << ' ';
    outStream << rect.pos.x + rect.width / 2 << ' ' << rect.pos.y + rect.height / 2 << ' ';
  }
  for (size_t i = 0; i < size; ++i) {
    isoScale(arr[i], point, k);
  }

  area = 0;
  for (size_t i = 0; i < size; ++i) {
    area += arr[i]->getArea();
  }
  outStream << '\n' << area << ' ';
  for (size_t i = 0; i < size; ++i) {
    rect = arr[i]->getFrameRect();
    outStream << rect.pos.x - rect.width / 2 << ' ' << rect.pos.y - rect.height / 2 << ' ';
    outStream << rect.pos.x + rect.width / 2 << ' ' << rect.pos.y + rect.height / 2 << ' ';
  }
}

int main()
{
  size_t capacity = 10;
  size_t size = 0;
  Shape** arr = new Shape*[capacity];
  std::string name = " ";

  while (std::cin) {
    std::cin >> name;
    try {
      if (size == capacity) {
        capacity += 10;
        Shape **temp = new Shape *[capacity];
        for (size_t i = 0; i < size; ++i) {
          temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
      }

      if (name == "RECTANGLE") {
        arr[size] = makeRectangle(std::cin);
      } else if (name == "ELLIPSE") {
        arr[size] = makeEllipse(std::cin);
      } else if (name == "COMPLEXQUAD") {
        arr[size] = makeComplexquad(std::cin);
      } else if (name == "SCALE") {
        output(std::cout, std::cin, arr, size);
        return 0;
      } else {
        continue;
      }
    }
    catch (const std::exception& err) {
      std::cerr << "Error: " << err.what();
      return 1;
    }
    size += 1;
  }
  std::cerr << "Error: scale command not found";
  return 1;
}