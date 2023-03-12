#include "complexquad.h"
#include <stdexcept>

point_t getCenter(const point_t* arr)
{
  point_t res{0, 0};
  if (arr[3].x == arr[0].x && arr[2].x == arr[1].x) {
    throw std::invalid_argument("Intersection point doesn't exist or there are multiple of them");
  } else if (arr[3].x == arr[0].x) {
    double k2 = (arr[2].y - arr[1].y) / (arr[2].x - arr[1].x);
    double b2 = arr[2].y - k2 * arr[2].x;
    res.x = arr[3].x;
    res.y = k2 * res.x + b2;
  } else if (arr[2].x == arr[1].x) {
    double k1 = (arr[3].y - arr[0].y) / (arr[3].x - arr[0].x);
    double b1 = arr[3].y - k1 * arr[3].x;
    res.x = arr[2].x;
    res.y = k1 * res.x + b1;
  } else {
    double k1 = (arr[3].y - arr[0].y) / (arr[3].x - arr[0].x);
    double b1 = arr[3].y - k1 * arr[3].x;
    double k2 = (arr[2].y - arr[1].y) / (arr[2].x - arr[1].x);
    double b2 = arr[2].y - k2 * arr[2].x;
    if (k1 == k2) {
      throw std::invalid_argument("Intersection point doesn't exist");
    }
    res.x = (b2 - b1) / (k1 - k2);
    res.y = k1 * res.x + b1;
  }
  return res;
}

void getBorders(point_t* res, const point_t p1, const point_t p2)
{
  res[0].x = std::min(p1.x, p2.x);
  res[0].y = std::min(p1.y, p2.y);
  res[1].x = std::max(p1.x, p2.x);
  res[1].y = std::max(p1.y, p2.y);
}

void getBorders(point_t* res, const point_t* arr, const size_t size)
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

bool isIntersection(const point_t center, const point_t* arr)
{
  point_t borders[2]{0, 0, 0, 0};
  getBorders(borders, arr[0], arr[3]);
  if (borders[0].x > center.x || borders[0].y > center.y) {
    return false;
  }
  if (borders[1].x < center.x || borders[1].y < center.y) {
    return false;
  }
  getBorders(borders, arr[1], arr[2]);
  if (borders[0].x > center.x || borders[0].y > center.y) {
    return false;
  }
  if (borders[1].x < center.x || borders[1].y < center.y) {
    return false;
  }
  return true;
}

double getTriangleArea(const point_t p1, const point_t p2, const point_t p3)
{
  return (std::abs(((p2.x - p1.x) * (p3.y - p1.y)) - ((p3.x - p1.x) * (p2.y - p1.y))) / 2);
}

Complexquad::Complexquad(const point_t p0, const point_t p1, const point_t p2, const point_t p3):
  pointArr_{p0, p1, p2, p3},
  center_(getCenter(pointArr_))
{
  if (!isIntersection(center_, pointArr_)) {
    throw std::invalid_argument("Intersection point doesn't exist");
  }
}

double Complexquad::getArea() const
{
  double res = getTriangleArea(center_, pointArr_[0], pointArr_[1]);
  res += getTriangleArea(center_, pointArr_[2], pointArr_[3]);
  return res;
}

rectangle_t Complexquad::getFrameRect() const
{
  point_t borders[2]{0, 0, 0, 0};
  getBorders(borders, pointArr_, 4);
  rectangle_t res{0};
  res.width = borders[1].x - borders[0].x;
  res.height = borders[1].y - borders[0].y;
  res.pos = {borders[0].x + res.width / 2, borders[0].y + res.height / 2};
  return res;
}

void Complexquad::move(point_t point)
{
  vector_t vector = getVector(center_, point);
  addVector(center_, vector);
  for (size_t i = 0; i < 4; ++i) {
    addVector(pointArr_[i], vector);
  }
}

void Complexquad::move(double dx, double dy)
{
  addVector(center_, {dx, dy});
  for (size_t i = 0; i < 4; ++i) {
    addVector(pointArr_[i], {dx, dy});
  }
}

void Complexquad::scale(double k)
{
  for (size_t i = 0; i < 4; ++i) {
    vector_t vector = getVector(center_, pointArr_[i]);
    addVector(pointArr_[i], vector * (k - 1));
  }
}

Shape *Complexquad::clone()
{
  return new Complexquad(pointArr_[0], pointArr_[1], pointArr_[2], pointArr_[3]);
}
