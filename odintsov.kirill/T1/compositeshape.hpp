#ifndef COMPOSITESHAPE_HPP
#define COMPOSITESHAPE_HPP

#include <cstddef>
#include <iosfwd>
#include "shape.hpp"
#include "base-types.hpp"

namespace odintsov {
  class CompositeShape {
    public:
      CompositeShape();
      explicit CompositeShape(size_t cap);
      CompositeShape(const CompositeShape& shp);
      CompositeShape(CompositeShape&& shp);
      ~CompositeShape();

      CompositeShape& operator=(const CompositeShape& shp);
      CompositeShape& operator=(CompositeShape&& shp);
      Shape* operator[](size_t id);
      const Shape* operator[](size_t id) const;

      double getArea() const;
      rectangle_t getFrameRect() const;
      void move(double dx, double dy);
      void move(const point_t& pos);
      void scale(double k);

      void push_back(Shape* shp);
      void pop_back();
      void quiet_pop_back();
      Shape* at(size_t id);
      const Shape* at(size_t id) const;
      bool empty() const;
      size_t size() const;
    private:
      size_t size_;
      size_t cap_;
      Shape** shapes_;

      void extend(size_t newCap);
      void clear();
      point_t getMiddlePoint() const;
  };
  std::ostream& outputCompositeShape(std::ostream& out, const CompositeShape& composite);
}

#endif
