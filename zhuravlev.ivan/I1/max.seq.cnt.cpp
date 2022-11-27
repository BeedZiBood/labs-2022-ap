#include "max.seq.cnt.h"
#include <limits>
#include <stdexcept>

int MaxSeqRow::operator()(int value)
{
    const unsigned int maximum_of_unsigned_int = std::numeric_limits < unsigned int >::max();
    if (func_value && func_previous_value)
    {
        if (max_seq_row == maximum_of_unsigned_int)
        {
            std::overflow_error("Error overflow");
        }
        if (func_previous_value == func_value)
        {
            current_seq_row++;
            if (current_seq_row > max_seq_row)
            {
                max_seq_row = current_seq_row;
            }
            else
            {
                current_seq_row = 0;
            }
        }
    }
    func_value = value;
    func_previous_value = func_value;
}
