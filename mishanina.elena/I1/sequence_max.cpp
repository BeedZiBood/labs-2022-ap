#include "sequence_max.h"

Seq_after_max::Seq_after_max():
 num(0),
 max_num(0),
 count_after_max(0)
{}

void Seq_after_max::operator()(int num)
{
  if (max_num < num)
  {
    count_after_max = 0;
    max_num = num;
  }
  else
  {
    count_after_max++;
  }
}

int Seq_after_max::get_count_after_max() const
{
  return count_after_max;
}
