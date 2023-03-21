#include "max_seq_cnt.h"
#include <limits>
#include <stdexcept>

void MaxSeqRow::operator()(int value)
{
  const unsigned int max_unsigned_int = std::numeric_limits< unsigned int >::max();
  func_value = value;
  func_previous_value = func_value;
  if (func_value && func_previous_value)
  {
    if (func_previous_value == func_value && current_seq_row > max_unsigned_int - 1 )
    {
      throw std::overflow_error("Overflow!");
    }
    else if (func_previous_value == func_value)
    {
      current_seq_row++;
      if (current_seq_row > max_seq_row)
      {
        max_seq_row = current_seq_row;
      }
      else
      {
        current_seq_row = 1;
      }
    }
  }
}

