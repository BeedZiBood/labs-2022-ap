#include "golden_ratio.h"
#include <stdexcept>
#include <cmath>
#include "check_over_flow_size_t.h"

size_t goldenRatio(size_t capacity)
{
  const double gRatioK = (1 + std::sqrt(5)) / 2;
  const size_t addend = static_cast< size_t >(std::ceil(capacity * (gRatioK - 1)));
  bool check_over_flow = checkOverFlowSizeT(capacity,addend);
  if (check_over_flow)
  {
    return capacity + addend;
  }
  else
  {
    throw std::overflow_error("Overflow");
  }
}
