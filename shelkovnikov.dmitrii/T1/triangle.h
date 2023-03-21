#ifndef SPBSPU_LABS_2022_AAP_904_A_TRIANGLE_H
#define SPBSPU_LABS_2022_AAP_904_A_TRIANGLE_H
#include "shape.h"
namespace dimkashelk
{
  class Triangle: public Shape
  {
  public:
    Triangle();
    Triangle(point_t point1, point_t point2, point_t point3);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double delta_x, double delta_y) override;
    Shape* clone() const override;
    void unsafeScale(double k) noexcept override;
    Triangle rotate(double theta) const;
  private:
    point_t points_[3];
    point_t getCenter() const;
  };
}
#endif
