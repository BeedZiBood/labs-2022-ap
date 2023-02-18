#include "outputframerect.hpp"
#include "base-func.hpp"

void tarasenko::outputFrameRect(std::ostream & output, const rectangle_t & rect)
{
  point_t point_ld = getPointLDRect(rect);
  point_t point_ru = getPointRURect(rect);
  output << point_ld.x_ << " " << point_ld.y_ << " " << point_ru.x_ << " " << point_ru.y_;
}
