#include "makeShapes.h"

Shape* makeRectangle(std::istream& input)
{
  point_t p1{0, 0};
  point_t p2{0, 0};
  input >> p1.x;
  input >> p1.y;
  input >> p2.x;
  input >> p2.y;
  return new Rectangle(p1, p2);
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
  return new Complexquad(points[0], points[2], points[3], points[1]);
}
