#include <iostream>
#include <iomanip>
#include "shape.h"
#include "workWithArray.h"
#include "rectangle.h"
#include "concave.h"
#include "complexquad.h"
#include "supportFunctions.h"

std::istream &inputArray(std::istream &in, double *coords, const size_t size)
{
  for (size_t i = 0; i < size; i++) {
    in >> coords[i];
  }
  return in;
}

std::ostream &outputData(std::ostream &out, const Shape *const *shapes, const size_t size)
{
  double sumArea = 0.0;
  for (size_t i = 0; i < size; i++) {
    sumArea += shapes[i]->getArea();
  }
  out << std::fixed << std::setprecision(1) << sumArea;
  double leftBottomX = 0.0;
  double leftBottomY = 0.0;
  double rightTopX = 0.0;
  double rightTopY = 0.0;
  for (size_t i = 0; i < size; i++) {
    leftBottomX = shapes[i]->getFrameRect().pos.x - shapes[i]->getFrameRect().width / 2;
    leftBottomY = shapes[i]->getFrameRect().pos.y - shapes[i]->getFrameRect().height / 2;
    rightTopX = shapes[i]->getFrameRect().pos.x + shapes[i]->getFrameRect().width / 2;
    rightTopY = shapes[i]->getFrameRect().pos.y + shapes[i]->getFrameRect().height / 2;
    out << " " << leftBottomX << " " << leftBottomY << " " << rightTopX << " " << rightTopY;
  }
  out << "\n";
  return out;
}

int main()
{
  bool isScale = false;
  size_t size = 0;
  size_t capacity = 10;
  point_t zoomCenter = {0, 0};
  double ratio = 0.0;
  bool isAdded = false;
  std::string figureName = "";
  Shape **shapes = new Shape*[capacity];
  double coords[8] = {0.0};
  while (std::cin) {
    std::cin >> figureName;
    try {
      if (size == capacity) {
        expandArray(shapes, capacity);
        Shape **newShapes = expandArray(shapes, capacity);
        delete [] shapes;
        shapes = newShapes;
      }
      if (figureName == "RECTANGLE") {
        if (!inputArray(std::cin, coords, 4)) {
          std::cerr << "Error while reading";
          continue;
        }
        point_t point1 = {coords[0], coords[1]};
        point_t point2 = {coords[2], coords[3]};
        shapes[size] = new Rectangle(point1, point2);
        isAdded = true;
      }
      if (figureName == "CONCAVE") {
        if (!inputArray(std::cin, coords, 8)) {
          std::cerr << "Error while reading";
          continue;
        }
        point_t point1 = {coords[0], coords[1]};
        point_t point2 = {coords[2], coords[3]};
        point_t point3 = {coords[4], coords[5]};
        point_t point4 = {coords[6], coords[7]};
        shapes[size] = new Concave(point1, point2, point3, point4);
        isAdded = true;
      }
      if (figureName == "COMPLEXQUAD") {
        if (!inputArray(std::cin, coords, 8)) {
          std::cerr << "Error while reading";
          continue;
        }
        point_t point1 = {coords[0], coords[1]};
        point_t point2 = {coords[2], coords[3]};
        point_t point3 = {coords[4], coords[5]};
        point_t point4 = {coords[6], coords[7]};
        shapes[size] = new Complexquad(point1, point2, point3, point4);
        isAdded = true;
      }
      if (isAdded) {
        size++;
        isAdded = false;
      }
      if (figureName == "SCALE") {
        std::cin >> zoomCenter.x >> zoomCenter.y >> ratio;
        if (!std::cin) {
          std::cerr << "Error while reading";
          break;
        }
        if (size > 0) {
          isScale = true;
        }
        break;
      }
    }
    catch (const std::invalid_argument &e) {
      std::cerr << e.what();
    }
    catch (...) {
      std::cerr << "Error while work with figures";
      deleteArray(shapes, size);
      return 2;
    }
  }
  if (isScale) {
    outputData(std::cout, shapes, size);
    try {
      for (size_t i = 0; i < size; i++) {
        fullScale(shapes[i], zoomCenter, ratio);
      }
    }
    catch (const std::invalid_argument &e) {
      std::cerr << e.what();
      deleteArray(shapes, size);
      return 2;
    }
    outputData(std::cout, shapes, size);
    deleteArray(shapes, size);
  } else {
    std::cerr << "No scale?";
    deleteArray(shapes, size);
    return 2;
  }
}
