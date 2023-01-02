#ifndef SPBSPU_LABS_2022_AAP_904_A_RECTANGLE_H
#define SPBSPU_LABS_2022_AAP_904_A_RECTANGLE_H
#include "shape.h"
namespace dimkashelk
{
  class Rectangle: virtual public Shape
  {
  public:
    explicit Rectangle(rectangle_t rectangle);
    Rectangle(point_t point_1, point_t point_2);
    Rectangle(const Rectangle &rect) = delete;
    Rectangle(Rectangle &&rect) = delete;
    Rectangle& operator=(const Rectangle &other) = delete;
    Rectangle& operator=(Rectangle &&tmp) = delete;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double delta_x, double delta_y) override;
    void scale(double k) override;
    Shape* clone() const override;
  private:
    rectangle_t rectangle_;
  };
}
#endif
