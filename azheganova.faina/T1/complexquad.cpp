#include "complexquad.h"
#include <iostream>
#include <stdexcept>

Complexquad::Complexquad()
{}

Complexquad::Complexquad(point_t pos1, point_t pos2, point_t pos3, point_t pos4):
  complexquad1{pos1, pos2, pos3, pos4}
{}

Complexquad::Complexquad(const Complexquad &tmp):
  complexquad1{tmp.complexquad1[0], tmp.complexquad1[1], tmp.complexquad1[2], tmp.complexquad1[3]}
{}
Complexquad::Complexquad(Complexquad &&tmp):
  complexquad1{tmp.complexquad1[0], tmp.complexquad1[1], tmp.complexquad1[2], tmp.complexquad1[3]}
{}
double Complexquad::getArea() const
{
  point_t center = {(complexquad1[0].x + complexquad1[1].x) / 2, (complexquad1[0].y + complexquad1[1].y) / 2};
  double firsttriangle1 = 0.0;
  double firsttriangle2 = 0.0;
  double secondtriangle1 = 0.0;
  double secondtriangle2 = 0.0;
  double areaforcomplexquad = 0.0;
  firsttriangle1 = (complexquad1[0].x - complexquad1[3].x) * (center.y - complexquad1[3].y);
  firsttriangle2 = (center.x - complexquad1[3].x) * (complexquad1[0].y - complexquad1[3].y);
  secondtriangle1 = (complexquad1[2].x - complexquad1[1].x) * (center.y - complexquad1[1].y);
  secondtriangle2 = (center.x - complexquad1[1].x) * (complexquad1[2].y - complexquad1[1].y);
  areaforcomplexquad = (0.5 * (secondtriangle1 - secondtriangle2)) + (0.5 * (firsttriangle1 - firsttriangle2));
  return std::abs(areaforcomplexquad);
}

rectangle_t Complexquad::getFrameRect() const
{
  point_t complexquad1[4] = {(complexquad1[0].x + complexquad1[1].x) / 2, (complexquad1[0].y + complexquad1[1].y) / 2};
  double maxx1 = std::max(complexquad1[2].x, complexquad1[3].x);
  double maxy1 = std::max(complexquad1[2].y, complexquad1[3].y);
  double minx1 = std::min(complexquad1[2].x, complexquad1[3].x);
  double miny1 = std::min(complexquad1[2].y, complexquad1[3].y);
  double maxx = std::max(complexquad1[0].x, std::max(complexquad1[1].x, maxx1));
  double maxy = std::max(complexquad1[0].y, std::max(complexquad1[1].y, maxy1));
  double minx = std::min(complexquad1[0].x, std::min(complexquad1[1].x, minx1));
  double miny = std::min(complexquad1[0].y, std::min(complexquad1[1].y, miny1));
  return makeFrame(point_t {(minx + maxx) / 2}, point_t {(maxy + miny) / 2});
}
void Complexquad::move(point_t point)
{
  point_t center = {(complexquad1[0].x + complexquad1[1].x) / 2, (complexquad1[0].y + complexquad1[1].y) / 2};
  return move(point.x - center.x, point.y - center.y);
}
void Complexquad::move(double dx, double dy)
{
  complexquad1[0].x += dx;
  complexquad1[0].y += dy;
  complexquad1[1].x += dx;
  complexquad1[1].y += dy;
  complexquad1[2].x += dx;
  complexquad1[2].y += dy;
  complexquad1[3].x += dx;
  complexquad1[3].y += dy;
}
void Complexquad::scale(double k)
{
  if (k <= 0)
  {
    std::cout << "incorrect value";
  }
  point_t center = {(complexquad1[0].x + complexquad1[1].x) / 2, (complexquad1[0].y + complexquad1[1].y) / 2};
  complexquad1[0].x = k * (complexquad1[0].x - center.x) + center.x;
  complexquad1[1].x = k * (complexquad1[1].x - center.x) + center.x;
  complexquad1[2].x = k * (complexquad1[2].x - center.x) + center.x;
  complexquad1[3].x = k * (complexquad1[3].x - center.x) + center.x;
}

Shape* Complexquad::clone() const
{
  Complexquad *copy = new Complexquad(complexquad1[0], complexquad1[1], complexquad1[2], complexquad1[3]);
  return copy;
}
