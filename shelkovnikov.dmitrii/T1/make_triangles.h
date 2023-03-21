#ifndef SPBSPU_LABS_2022_AAP_904_A_MAKE_TRIANGLES_H
#define SPBSPU_LABS_2022_AAP_904_A_MAKE_TRIANGLES_H
#include <cstddef>
#include "triangle.h"
namespace dimkashelk
{
  Triangle* makeTriangles(const point_t *points, size_t size);
  class TriangulatePoints
  {
  public:
    TriangulatePoints(const point_t *points, size_t size);
    ~TriangulatePoints();
    Triangle operator()();
    bool hasNext() const;
  private:
    point_t *points_;
    size_t size_;
    size_t point_;
  };
}
#endif
