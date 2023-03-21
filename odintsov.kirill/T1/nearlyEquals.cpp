#include "nearlyEquals.hpp"
#include <limits>
#include <cmath>
#include <algorithm>
#include "base-types.hpp"

bool odintsov::nearlyEquals(double a, double b, double epsilon)
{
  //src: https://floating-point-gui.de/errors/comparison/
  double absA = std::abs(a);
  double absB = std::abs(b);
  double diff = std::abs(a - b);

  constexpr double dblMinNormal = std::numeric_limits< double >::min();
  if (a == b) {
    return true;
  } else if (a == 0 || b == 0 || (absA + absB < dblMinNormal)) {
    return diff < (epsilon * dblMinNormal);
  } else {
    return diff / std::min((absA + absB), std::numeric_limits< double >::max()) < epsilon;
  }
}


bool odintsov::nearlyEquals(const point_t& a, const point_t& b, double epsilon)
{
  return nearlyEquals(a.x, b.x, epsilon) && nearlyEquals(a.y, b.y, epsilon);
}
