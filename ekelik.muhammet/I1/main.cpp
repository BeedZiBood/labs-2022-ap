#include <iostream>
#include "longest_desc_seq.h"
#include "sum_prev_2_elements.h"

int main()
{
  int value = 0;
  LongestDescSequence longest_desc_seq;
  SumPrev2Elements sum_prev_2_elements;

  do
  {
    std::cin >> value;
    if (!std::cin)
    {
      std::cout << "input error" << "\n";
      return 1;
    }
    if (value == 0)
    {
      break;
    }
    longest_desc_seq(value);
    if (longest_desc_seq.current_length > 2)
    {
      sum_prev_2_elements(value, longest_desc_seq.max_value, value);
    }
  }
  while (value && std::cin);

  std::cout << "Longest Decreasing Sequence Length-" << longest_desc_seq.longest_length << '\n';
  std::cout << "NumElemEqToSumPrev2-" << sum_prev_2_elements.numEqualToSum << '\n';
}
