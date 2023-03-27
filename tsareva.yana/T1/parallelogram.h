#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H
#include "shape.h"
namespace tsareva
{
  point_t getFirstPoint(point_t f_p, point_t s_p, point_t t_p);
  point_t getSecondPoint(point_t f_p, point_t s_p, point_t t_p);
  point_t getThirdPoint(point_t f_p, point_t s_p, point_t t_p);

  class Parallelogram: public Shape
  {
  public:
    Parallelogram(point_t first, point_t second, point_t third);
    double getArea() const override;
    rectangle_t getFrameRectangle() const override;
    void move(point_t position) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    point_t first_;
    point_t second_;
    point_t third_;
  };
}
#endif
