#ifndef SPBSPU_LABS_2022_AAP_904_A_REGULAR_H
#define SPBSPU_LABS_2022_AAP_904_A_REGULAR_H
#include <cstddef>
#include "shape.h"
#include "triangle.h"
namespace dimkashelk
{
  class Regular: public Shape
  {
  public:
    Regular(point_t point_1, point_t point_2, point_t point_3);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double delta_x, double delta_y) override;
    void unsafeScale(double k) noexcept override;
    Shape* clone() const override;
  private:
    Triangle triangle_;
    size_t size_;
    point_t center_;
    Regular(const Regular &regular);
  };
}
#endif
