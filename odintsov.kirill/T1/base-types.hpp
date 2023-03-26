#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

#include <cstddef>
#include <iosfwd>

namespace odintsov {
  struct point_t {
    double x, y;
  };
  struct rectangle_t {
    double width, height;
    point_t pos;
  };
  class FrameRectBuilder {
    public:
      explicit FrameRectBuilder(const point_t& p);
      explicit FrameRectBuilder(const rectangle_t& r);

      FrameRectBuilder& operator<<(const point_t& p);
      FrameRectBuilder& operator<<(const rectangle_t& r);

      rectangle_t rect();
    private:
      point_t bl_, tr_;
  };
  void movePoint(point_t& p, double dx, double dy);
  void isoScalePoint(point_t& p, const point_t& anchor, double k);
  rectangle_t getFrameRectFromCorners(const point_t& bl, const point_t& tr);
  point_t getFrameRectBottomLeftCorner(const rectangle_t& rect);
  point_t getFrameRectTopRightCorner(const rectangle_t& rect);
  std::ostream& outputFrameRect(std::ostream& out, const rectangle_t& rect);
  bool isPointInRectangle(const point_t& p, const rectangle_t& rect);
}

#endif
