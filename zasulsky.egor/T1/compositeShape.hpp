#ifndef COMPOSITESHAPE_HPP
#define COMPOSITESHAPE_HPP
#include <iosfwd>
#include "base-types.hpp"
#include "shape.hpp"

namespace zasulsky
{
  class CompositeShape
  {
  public:
    explicit CompositeShape(size_t cap);
    CompositeShape(const CompositeShape& cshp);
    CompositeShape(CompositeShape&& cshp);
    ~CompositeShape();
    CompositeShape& operator=(const CompositeShape& cshp);
    CompositeShape& operator=(CompositeShape&& cshp);
    Shape* operator[](size_t id);
    const Shape* operator[](size_t id) const;

    template< class F >
    F traverse(F f) const;
    template< class F >
    F traverse(F f);

    void move(double dx, double dy);
    void move(const point_t& position);
    void scale(double k);
    void unsafeScale(double k);
    void push_back(Shape* shp);
    void pop_back();
    Shape* at(size_t id);
    const Shape* at(size_t id) const;

    bool empty() const;
    size_t size() const;

  private:
    size_t cap_;
    size_t size_;
    Shape** shape_;
    point_t getCenter();
    void extend(size_t capDiff);
    void purge();
  };
  void isoScale(CompositeShape& shp, const point_t& center, double k);
  std::ostream& outputComposite(std::ostream& out, const CompositeShape& composite);
  struct CompositeArea
  {
    double area;
    CompositeArea();
    void operator()(const Shape& shp);
  };
  struct CompositeCorners
  {
    point_t p1;
    point_t p2;
    CompositeCorners();
    void operator()(const Shape& shp);
  private:
    bool isFirstCall_;
  };
}
#endif