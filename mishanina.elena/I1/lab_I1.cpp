#include <iostream>
#include "sequence_interaction.h"
#include "sequence_max.h"

int main()
{
  int num = 0;
  Suitable_seq sequence1;
  Seq_after_max sequence2;
  do {
   std::cout << "Enter number\n";
   std::cin >> num;
   sequence1(num);
   sequence2(num);
  }
  while (num != 0 && !std::cin.fail());
  if (std::cin.fail())
  {
    std::cerr << "INPUT ERROR: a number must be entered";
    return 1;
  }
  else
  {
    std::cout << sequence1.get_count_of_elements()
              << " elements of this sequence are smaller than the previous element, but larger than the next one.\n";
    std::cout << sequence2.get_count_after_max() << " elements of this sequence are placed after the maximum element.\n";
    return 0;
  }
}
