#include "supportFunctions.h"
#include <algorithm>
#include <stdexcept>

void movePoint(point_t &p, double dx, double dy)
{
  p.x += dx;
  p.y += dy;
}

void movePointBecauseOfScale(point_t &p, const point_t &zoomCenter, double k)
{
  movePoint(p, (p.x - zoomCenter.x) * (k - 1.0), (p.y - zoomCenter.y) * (k - 1.0));
}

void fullScale(Shape *shape, const point_t &zoomCenter, double k)
{
  point_t a1;
  a1.x = shape->getFrameRect().pos.x - shape->getFrameRect().width / 2;
  a1.y = shape->getFrameRect().pos.y - shape->getFrameRect().height / 2;
  shape->move(zoomCenter);
  point_t a2;
  a2.x = shape->getFrameRect().pos.x - shape->getFrameRect().width / 2;
  a2.y = shape->getFrameRect().pos.y - shape->getFrameRect().height / 2;
  double dx = a1.x - a2.x;
  double dy = a1.y - a2.y;
  shape->scale(k);
  movePointBecauseOfScale(a2, zoomCenter, k);
  shape->move(k * dx, k * dy);
}

bool isIntersectionOfSegments(const point_t &point1, const point_t &point2, const point_t &point3, const point_t &point4)
{
  point_t p1, p2, p3, p4;
  if (point1.x < point2.x) {
    p1 = point1;
    p2 = point2;
  } else {
    p1 = point2;
    p2 = point1;
  }
  if (point3.x < point4.x) {
    p3 = point3;
    p4 = point4;
  } else {
    p3 = point4;
    p4 = point3;
  }
  if (p2.x <= p3.x) {
    return false;
  }
  if (p1.x - p2.x == 0 && p3.x - p4.x == 0) {
    return false;
  }
  if (p1.x - p2.x == 0) {
    double xa = p1.x;
    double a2 = (p3.y - p4.y) / (p3.x - p4.x);
    double b2 = p3.y - a2 * p3.x;
    double ya = a2 * xa + b2;
    return p3.x <= xa && p4.x >= xa && std::min(p1.y, p2.y) <= ya && std::max(p1.y, p2.y) >= ya;
  }
  if (p3.x - p4.x == 0) {
    double xa = p3.x;
    double a1 = (p1.y - p2.y) / (p1.x - p2.x);
    double b1 = p1.y - a1 * p1.x;
    double ya = a1 * xa + b1;
    return p1.x <= xa && p2.x >= xa && std::min(p3.y, p4.y) <= ya && std::max(p3.y, p4.y) >= ya;
  }
  double a1 = (p1.y - p2.y) / (p1.x - p2.x);
  double a2 = (p3.y - p4.y) / (p3.x - p4.x);
  if (a1 == a2) {
    return false;
  }
  double b1 = p1.y - a1 * p1.x;
  double b2 = p3.y - a2 * p3.x;
  double xa = (b2 - b1) / (a1 - a2);
  return xa > std::max(p1.x, p3.x) && xa < std::min(p2.x, p4.x);
}
point_t getIntersectionPoint(const point_t &point1, const point_t &point2, const point_t &point3, const point_t &point4)
{
  point_t p1, p2, p3, p4;
  double x0 = 0.0, y0 = 0.0;
  if (point1.x < point2.x) {
    p1 = point1;
    p2 = point2;
  } else {
    p1 = point2;
    p2 = point1;
  }
  if (point3.x < point4.x) {
    p3 = point3;
    p4 = point4;
  } else {
    p3 = point4;
    p4 = point3;
  }
  if (p1.x - p2.x == 0) {
    x0 = p1.x;
    double a2 = (p3.y - p4.y) / (p3.x - p4.x);
    double b2 = p3.y - a2 * p3.x;
    y0 = a2 * x0 + b2;
  } else if (p3.x - p4.x == 0) {
    x0 = p3.x;
    double a1 = (p1.y - p2.y) / (p1.x - p2.x);
    double b1 = p1.y - a1 * p1.x;
    y0 = a1 * x0 + b1;
  } else {
    double a1 = (p1.y - p2.y) / (p1.x - p2.x);
    double a2 = (p3.y - p4.y) / (p3.x - p4.x);
    double b1 = p1.y - a1 * p1.x;
    double b2 = p3.y - a2 * p3.x;
    x0 = (b2 - b1) / (a1 - a2);
    y0 = (x0 - p1.x) * a1 + p1.y;
  }
  return {x0, y0};
}

