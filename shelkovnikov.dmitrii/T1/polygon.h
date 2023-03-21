#ifndef SPBSPU_LABS_2022_AAP_904_A_POLYGON_H
#define SPBSPU_LABS_2022_AAP_904_A_POLYGON_H
#include <cstddef>
#include "triangle.h"
namespace dimkashelk
{
  class Polygon: public Shape
  {
  public:
    Polygon(const point_t *points, size_t size);
    Polygon(const Polygon &polygon);
    ~Polygon();
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double delta_x, double delta_y) override;
    void unsafeScale(double k) noexcept override;
    Shape* clone() const override;
  private:
    size_t count_;
    Triangle *triangles_;
    point_t center_;
  };
}
#endif
