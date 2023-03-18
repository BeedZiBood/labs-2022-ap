#ifndef RING_H
#define RING_H

#include "shape.h"

class Ring: public Shape
{
public:
  Ring(point_t m_center, double m_externalRadius, double m_internalRadius);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(point_t newPos) override;
  void unsafeScale(double k) override;
  Shape* clone() const override;
private:
  point_t m_center;
  double m_internalRadius;
  double m_externalRadius;

};

#endif
