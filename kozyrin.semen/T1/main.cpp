#include <iostream>
#include "makeShapes.h"
#include <iomanip>

void printRow(std::ostream& outStream, Shape** arr, size_t size)
{
  double area = 0;
  for (size_t i = 0; i < size; ++i) {
    area += arr[i]->getArea();
  }
  outStream << std::setprecision(1) << std::fixed << area << ' ';
  rectangle_t rect = {0, 0, 0, 0};
  for (size_t i = 0; i < size; ++i) {
    rect = arr[i]->getFrameRect();
    outStream << rect.pos.x - rect.width / 2 << ' ' << rect.pos.y - rect.height / 2 << ' ';
    outStream << rect.pos.x + rect.width / 2 << ' ' << rect.pos.y + rect.height / 2;
    if (i != size - 1) {
      outStream << ' ';
    }
  }
  outStream << '\n';
}

int printArr(std::ostream& errStream, std::ostream& outStream, std::istream& inStream, Shape** arr, size_t size)
{
  if (size == 0) {
    errStream << "Error: nothing to scale";
    delete[] arr;
    return 1;
  }
  double x = 0;
  double y = 0;
  inStream >> x;
  inStream >> y;
  point_t point{x, y};
  double k = 0;
  inStream >> k;
  if (k <= 0) {
    errStream << "Error: scale coefficient must be greater than zero";
    return 2;
  } else {
    printRow(outStream, arr, size);
    for (size_t i = 0; i < size; ++i) {
      isoScale(arr[i], point, k);
    }
    printRow(outStream, arr, size);
  }

  for (size_t i = 0; i < size; ++i) {
    delete arr[i];
  }
  delete[] arr;
  return 0;
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
        return printArr(std::cerr, std::cout, std::cin, arr, size);
      } else {
        continue;
      }
    }
    catch (const std::exception& err) {
      std::cerr << "Error: " << err.what() << '\n';
      continue;
    }
    size += 1;
  }
  for (size_t i = 0; i < size; ++i) {
    delete arr[i];
  }
  delete[] arr;
  std::cerr << "Error: scale command not found";
  return 1;
}
