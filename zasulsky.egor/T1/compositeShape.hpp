#ifndef COMPOSITESHAPE_HPP
#define COMPOSITESHAPE_HPP
#include <iosfwd>
#include "base-types.hpp"
#include "Shape.hpp"

namespace zasulsky
{
  class CompositeShape
  {
  public:
    explicit CompositeShape(size_t cap);
    ~CompositeShape();

    Shape* operator[](size_t id);
    const Shape* operator[](size_t id) const;

    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(double dx, double dy);
    void move(const point_t& position);
    void scale(double k);
    void push_back(Shape* shp);
    void pop_back();
    Shape* at(size_t id);
    const Shape* at(size_t id) const;

    bool empty() const;
    size_t size() const;

  private:
    size_t size_;
    size_t cap_;
    Shape** shape_;
    point_t getCenter();
    void extend(size_t capDiff);
  };
  void isoScale(CompositeShape& shp, const point_t& center, double k);
  std::ostream& outputComposite(std::ostream& out, const CompositeShape& composite);
}
#endif
