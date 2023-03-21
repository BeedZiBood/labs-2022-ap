#include "iso-scale.hpp"

void chemodurov::isoScale(Shape * s, const point_t & pos, double k)
{
  point_t fst_pos = s->getFrameRect().pos;
  s->move(pos);
  point_t sec_pos = s->getFrameRect().pos;
  s->scale(k);
  double dx = (fst_pos.x - sec_pos.x) * k;
  double dy = (fst_pos.y - sec_pos.y) * k;
  s->move(dx, dy);
}
