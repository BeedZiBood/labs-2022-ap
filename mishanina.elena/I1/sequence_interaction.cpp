#include "sequence_interaction.h"

Suitable_seq::Suitable_seq():
 num(0),
 previous_num(0),
 current_num(0),
 next_num(0),
 count_of_elements(0)
{}

void Suitable_seq::operator()(int num)
{
  if (previous_num == 0)
  {
    previous_num = num;
  }
  else if (current_num == 0)
  {
    current_num = num;
  }
  else
  {
    next_num = num;
    if (current_num < previous_num && current_num > next_num)
    {
      count_of_elements++;
    }
    previous_num = current_num;
    current_num = next_num;
  }
}

int Suitable_seq::get_count_of_elements() const
{
  return count_of_elements;
}
