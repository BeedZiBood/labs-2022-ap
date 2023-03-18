#include <iostream>
#include "countequalelements.h"
#include "countpythagoreanthrees.h"
#include "ispyth.h"

int main()
{
  int value = 0;
  int pred_value = 0;
  int count_of_pythagorean_threes = 0;
  int program_launch_number = 0;
  int equal_element_counter = 0;
  int max_equal_element = 0;
  int x = 0;
  int y = 0;
  int z = 0;
  do
  {
    pred_value = value;
    std::cin >> value;
    if (std::cin)
    {
      countEqualElements(value, pred_value, equal_element_counter, max_equal_element);
      countPythagoreanThrees(value, program_launch_number, count_of_pythagorean_threes, x, y, z);
      program_launch_number += 1;
    }
  }
  while (value && std::cin);
  if (!std::cin)
  {
    std::cout << "Error...\n";
  }
  std::cout << "Count of Pythagorean threes = " << count_of_pythagorean_threes << "\n";
  std::cout << "The maximum equal elements = " << max_equal_element << "\n";
  return 0;
}
