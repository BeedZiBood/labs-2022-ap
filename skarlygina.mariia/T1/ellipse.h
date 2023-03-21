#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "shape.h"
class Ellipse: public Shape
{
public:
  Ellipse(point_t center, double radius_vertical, double radius_horizontal);
  double getArea() const override;
  rectangle_t getFrameRectangle() const override;
  void move(point_t position) override;
  void move(double dx, double dy) override;
  void scale(double k) override;

private:
  point_t center_;
  double radius_vertical_, radius_horizontal_;
  bool isBadEllipse();
};
#endif
