#ifndef SHAPE_H
#define SHAPE_H
#include <iomanip>
#include <ostream>
#include "base_types.h"

namespace kryuchkova
{
  class Shape
  {
  public:
    virtual std::string getName() const = 0;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t point) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double k);
    virtual void unsafeScale(double k) = 0;
    virtual Shape *clone() const = 0;
    bool operator<(const Shape &sh);
    virtual ~Shape() = default;
  };

  void isoScale(kryuchkova::Shape *shape, kryuchkova::point_t point, double k);
  void unsafeIsoScale(kryuchkova::Shape *shape, const point_t point, const double k);
  std::ostream& operator<<(std::ostream &out, const point_t &point);
  std::ostream& operator<<(std::ostream &out, const Shape &shape);

  Shape *inputRectangle(std::istream &in);
  Shape *inputCircle(std::istream &in);
  Shape *inputSquare(std::istream &in);

  point_t movePoint(point_t point, point_t dpoint);
  point_t scalePoint(point_t point, point_t pos, double k);
}

#endif
