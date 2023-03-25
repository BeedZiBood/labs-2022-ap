#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"
class Rectangle: public Shape {
 public:
  Rectangle(const point_t &point1, const point_t &point2);
  explicit Rectangle(const rectangle_t &rect);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(const point_t &pos) override;
  void scale(double k) override;
  ~Rectangle() override = default;
 private:
  rectangle_t rect_;
};
#endif
