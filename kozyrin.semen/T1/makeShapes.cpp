#include "makeShapes.h"

void kozyrin::inputPoints(std::istream& input, double* arr, size_t size)
{
  for (size_t i = 0; i < size; ++i) {
    input >> arr[i];
  }
}

kozyrin::Shape* kozyrin::makeRectangle(std::istream& input)
{
  double args[4]{0};
  inputPoints(input, args, 4);
  return new Rectangle({args[0], args[1]}, {args[2], args[3]});
}

kozyrin::Shape* kozyrin::makeEllipse(std::istream& input)
{
  double args[4]{0};
  inputPoints(input, args, 4);
  return new Ellipse({args[0], args[1]}, args[2], args[3]);
}

kozyrin::Shape* kozyrin::makeComplexquad(std::istream& input)
{
  point_t points[4]{0};
  double args[8]{0};
  inputPoints(input, args, 8);

  for (size_t i = 0; i < 4; ++i) {
    points[i] = {args[i * 2], args[i * 2 + 1]};
  }
  return new Complexquad(points[0], points[1], points[2], points[3]);
}
