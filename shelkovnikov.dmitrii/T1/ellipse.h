#ifndef SPBSPU_LABS_2022_AAP_904_A_ELLIPSE_H
#define SPBSPU_LABS_2022_AAP_904_A_ELLIPSE_H
#include "shape.h"
#include "triangle.h"
#include "base_types.h"
#include "polygon.h"
namespace dimkashelk
{
  class Ellipse: public Shape
  {
  public:
    Ellipse(point_t point, double height, double width);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double delta_x, double delta_y) override;
    void unsafeScale(double k) noexcept override;
    Shape* clone() const override;
  private:
    Polygon polygon_;
    explicit Ellipse(const Polygon &polygon);
  };
}
#endif
