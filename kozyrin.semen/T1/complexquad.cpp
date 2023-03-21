#include "complexquad.h"
#include <stdexcept>

kozyrin::point_t kozyrin::getSegIntersection(const std::array< point_t, 4 > coords)
{
  point_t res{0, 0};
  if (coords[0].x == coords[1].x && coords[2].x == coords[3].x) {
    throw std::invalid_argument("Intersection point doesn't exist or there are multiple of them");
  } else if (coords[0].x == coords[1].x) {
    double k2 = (coords[3].y - coords[2].y) / (coords[3].x - coords[2].x);
    double b2 = coords[2].y - k2 * coords[2].x;
    res.x = coords[0].x;
    res.y = k2 * res.x + b2;
  } else if (coords[2].x == coords[3].x) {
    double k1 = (coords[1].y - coords[0].y) / (coords[1].x - coords[0].x);
    double b1 = coords[0].y - k1 * coords[0].x;
    res.x = coords[2].x;
    res.y = k1 * res.x + b1;
  } else {
    double k1 = (coords[1].y - coords[0].y) / (coords[1].x - coords[0].x);
    double b1 = coords[0].y - k1 * coords[0].x;
    double k2 = (coords[3].y - coords[2].y) / (coords[3].x - coords[2].x);
    double b2 = coords[2].y - k2 * coords[2].x;
    if (k1 == k2) {
      throw std::invalid_argument("Intersection point doesn't exist");
    }
    res.x = (b2 - b1) / (k1 - k2);
    res.y = k1 * res.x + b1;
  }
  return res;
}

void kozyrin::getBorders(point_t* res, const point_t p1, const point_t p2)
{
  res[0].x = std::min(p1.x, p2.x);
  res[0].y = std::min(p1.y, p2.y);
  res[1].x = std::max(p1.x, p2.x);
  res[1].y = std::max(p1.y, p2.y);
}

void kozyrin::getBorders(point_t* res, const std::array< point_t, 4 > arr, const size_t size)
{
  double mx = arr[0].x;
  double mn = arr[0].x;
  for (size_t i = 1; i < size; ++i) {
    if (mx < arr[i].x) {
      mx = arr[i].x;
    }
    if (mn > arr[i].x) {
      mn = arr[i].x;
    }
  }
  res[0].x = mn;
  res[1].x = mx;
  mx = arr[0].y;
  mn = arr[0].y;
  for (size_t i = 1; i < size; ++i) {
    if (mx < arr[i].y) {
      mx = arr[i].y;
    }
    if (mn > arr[i].y) {
      mn = arr[i].y;
    }
  }
  res[0].y = mn;
  res[1].y = mx;
}

bool kozyrin::isIntersection(const point_t center, const std::array< point_t, 4 > arr)
{
  point_t borders[2]{0, 0, 0, 0};
  getBorders(borders, arr[0], arr[1]);
  if (borders[0].x >= center.x || borders[0].y >= center.y) {
    return false;
  }
  if (borders[1].x <= center.x || borders[1].y <= center.y) {
    return false;
  }
  getBorders(borders, arr[2], arr[3]);
  if (borders[0].x >= center.x || borders[0].y >= center.y) {
    return false;
  }
  if (borders[1].x <= center.x || borders[1].y <= center.y) {
    return false;
  }
  return true;
}

double kozyrin::getTriangleArea(const point_t p1, const point_t p2, const point_t p3)
{
  return (std::abs(((p2.x - p1.x) * (p3.y - p1.y)) - ((p3.x - p1.x) * (p2.y - p1.y))) / 2);
}

kozyrin::Complexquad::Complexquad(const point_t p0, const point_t p1, const point_t p2, const point_t p3):
  pointArr_{p0, p1, p2, p3}
{
  if (!isIntersection(getSegIntersection(pointArr_), pointArr_)) {
    throw std::invalid_argument("Intersection point doesn't exist");
  }
}

double kozyrin::Complexquad::getArea() const
{
  point_t center = getSegIntersection(pointArr_);
  double res = getTriangleArea(center, pointArr_[0], pointArr_[3]);
  res += getTriangleArea(center, pointArr_[1], pointArr_[2]);
  return res;
}

kozyrin::rectangle_t kozyrin::Complexquad::getFrameRect() const
{
  point_t borders[2]{0, 0, 0, 0};
  getBorders(borders, pointArr_, 4);
  rectangle_t res{0};
  res.width = borders[1].x - borders[0].x;
  res.height = borders[1].y - borders[0].y;
  res.pos = {borders[0].x + res.width / 2, borders[0].y + res.height / 2};
  return res;
}

void kozyrin::Complexquad::move(point_t point)
{
  vector_t vector = getVector(getSegIntersection(pointArr_), point);
  for (size_t i = 0; i < 4; ++i) {
    addVector(pointArr_[i], vector);
  }
}

void kozyrin::Complexquad::move(double dx, double dy)
{
  for (size_t i = 0; i < 4; ++i) {
    addVector(pointArr_[i], {dx, dy});
  }
}

void kozyrin::Complexquad::scale(double k)
{
  for (size_t i = 0; i < 4; ++i) {
    vector_t vector = getVector(getSegIntersection(pointArr_), pointArr_[i]);
    addVector(pointArr_[i], vector * (k - 1));
  }
}

kozyrin::Shape* kozyrin::Complexquad::clone()
{
  return new Complexquad(pointArr_[0], pointArr_[1], pointArr_[2], pointArr_[3]);
}
