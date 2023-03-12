#include "makeShapes.h"

Shape* makeRectangle(std::istream& input)
{
  double args[4]{0};
  for (size_t i = 0; i < 4; ++i) {
    input >> args[i];
  }
  return new Rectangle({args[0], args[1]}, {args[2], args[3]});
}

Shape* makeEllipse(std::istream& input)
{
  double args[4]{0};
  for (size_t i = 0; i < 4; ++i) {
    input >> args[i];
  }
  return new Ellipse({args[0], args[1]}, args[2], args[3]);
}

Shape* makeComplexquad(std::istream& input)
{
  point_t points[4]{0};
  double x = 0;
  double y = 0;
  for (size_t i = 0; i < 4; ++i) {
    input >> x;
    input >> y;
    points[i] = {x, y};
  }
  return new Complexquad(points[0], points[3], points[1], points[2]);
}
