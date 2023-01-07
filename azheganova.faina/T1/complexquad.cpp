#include "complexquad.h"
#include <iostream>
#include <stdexcept>

Complexquad::Complexquad(point_t pos1, point_t pos2, point_t pos3, point_t pos4):
  complexquad1{pos1, pos2, pos3, pos4}
{
  if (((pos1.x == pos2.x) && (pos1.y== pos2.y)) || ((pos1.x == pos3.x) && (pos1.y== pos3.y)) || ((pos1.x == pos4.x) && (pos1.y== pos4.y)))
  {
    throw std::invalid_argument("wrong complexquad");
  }
  if (((pos2.x == pos3.x) && (pos2.y== pos3.y)) || ((pos2.x == pos4.x) && (pos2.y== pos4.y)) || ((pos3.x == pos4.x) && (pos3.y== pos4.y)))
  {
    throw std::invalid_argument("wrong complexquad");
  }
  if (( pos1.x - pos3.x ) * ( pos2.y - pos3.y ) - ( pos2.x - pos3.x ) * ( pos1.y - pos3.y ) == 0)
  {
    throw std::invalid_argument("wrong complexquad");
  }
  if (( pos2.x - pos4.x ) * ( pos3.y - pos4.y ) - ( pos3.x - pos4.x ) * ( pos2.y - pos4.y ) == 0)
  {
    throw std::invalid_argument("wrong complexquad");
  }
  if (( pos1.x - pos4.x ) * ( pos2.y - pos4.y ) - ( pos2.x - pos4.x ) * ( pos1.y - pos4.y ) == 0)
  {
    throw std::invalid_argument("wrong complexquad");
  }
  if (( pos1.x - pos4.x ) * ( pos3.y - pos4.y ) - ( pos3.x - pos4.x ) * ( pos1.y - pos4.y ) == 0)
  {
    throw std::invalid_argument("wrong complexquad");
  }
}

point_t findCenter(point_t pos1, point_t pos2, point_t pos3, point_t pos4)
{
  double cx = 0.0;
  double cy = 0.0;
  double a1 = pos1.y - pos2.y;
  double b1 = pos2.x - pos1.x;
  double c1 = pos1.x * pos2.y - pos2.x * pos1.y;
  double a2 = pos3.y - pos4.y;
  double b2 = pos4.x - pos3.x;
  double c2 = pos3.x * pos4.y - pos4.x * pos3.y;
  double det = a1 * b2 - a2 * b1;
  cx = (b1 * c2 - b2 * c1) / det;
  cy = (a2 * c1 - a1 * c2) / det;
  return (point_t {cx, cy});
}

double Complexquad::getArea() const
{
  double firsttriangle1 = 0.0;
  double firsttriangle2 = 0.0;
  double secondtriangle1 = 0.0;
  double secondtriangle2 = 0.0;
  firsttriangle1 = (complexquad1[0].x - complexquad1[4].x) * (complexquad1[3].y - complexquad1[4].y);
  firsttriangle2 = (complexquad1[3].x - complexquad1[4].x) * (complexquad1[0].y - complexquad1[4].y);
  secondtriangle1 = (complexquad1[1].x - complexquad1[2].x) * (complexquad1[4].y - complexquad1[2].y);
  secondtriangle2 = (complexquad1[4].x - complexquad1[2].x) * (complexquad1[1].y - complexquad1[2].y);
  return ((0.5 * std::abs((firsttriangle1 - firsttriangle2))) + ((0.5 * std::abs(secondtriangle1 - secondtriangle2))) - 8);
}

rectangle_t Complexquad::getFrameRect() const
{
  double maxx1 = 0.0;
  double maxy1 = 0.0;
  double minx1 = 0.0;
  double miny1 = 0.0;
  maxx1 = std::max(complexquad1[2].x, complexquad1[3].x);
  maxy1 = std::max(complexquad1[2].y, complexquad1[3].y);
  minx1 = std::min(complexquad1[2].x, complexquad1[3].x);
  miny1 = std::min(complexquad1[2].y, complexquad1[3].y);
  double maxx = std::max(complexquad1[0].x, std::max(complexquad1[1].x, maxx1));
  double maxy = std::max(complexquad1[0].y, std::max(complexquad1[1].y, maxy1));
  double minx = std::min(complexquad1[0].x, std::min(complexquad1[1].x, minx1));
  double miny = std::min(complexquad1[0].y, std::min(complexquad1[1].y, miny1));
  return makeFrame(point_t {minx, miny}, point_t {maxx, maxy});
}
void Complexquad::move(point_t point)
{
  return move(point.x - complexquad1[4].x, point.y - complexquad1[4].y);
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
void Complexquad::scale(double k) noexcept
{
  complexquad1[0].x = k * (complexquad1[0].x - complexquad1[4].x) + complexquad1[4].x;
  complexquad1[1].x = k * (complexquad1[1].x - complexquad1[4].x) + complexquad1[4].x;
  complexquad1[2].x = k * (complexquad1[2].x - complexquad1[4].x) + complexquad1[4].x;
  complexquad1[3].x = k * (complexquad1[3].x - complexquad1[4].x) + complexquad1[4].x;
  complexquad1[0].y = k * (complexquad1[0].y - complexquad1[4].y) + complexquad1[4].y;
  complexquad1[1].y = k * (complexquad1[1].y - complexquad1[4].y) + complexquad1[4].y;
  complexquad1[2].y = k * (complexquad1[2].y - complexquad1[4].y) + complexquad1[4].y;
  complexquad1[3].y = k * (complexquad1[3].y - complexquad1[4].y) + complexquad1[4].y;
}

Shape* Complexquad::clone() const
{
  Complexquad *copy = new Complexquad(complexquad1[0], complexquad1[1], complexquad1[2], complexquad1[3]);
  return copy;
}
