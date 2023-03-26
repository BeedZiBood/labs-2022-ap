#ifndef CONCAVE_H
#define CONCAVE_H
#include "shape.h"
class Concave: public Shape
{
 public:
  Concave(const point_t &point1, const point_t &point2, const point_t &point3, const point_t &point4);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(const point_t &pos) override;
  void scale(double k) override;
  ~Concave() override = default;
 private:
  point_t p1_, p2_, p3_, p4_;
};
#endif
